#include "player.h"
#include "minion.h"
#include "card.h"
#include "enchantment.h"
#include "ritual.h"
#include "helper.h"
#include "board.h"
#include <memory>
#include "asciigraphics.h"

using namespace std;

Player::Player(int player, string name, string deckFile, bool shuffle):
    	player{player}, name{name}, deck{deckFile, shuffle} { 
    draw(5);
}

void Player::setOtherPlayer(Player *otherPlayer){
    this->otherPlayer = otherPlayer;
}


void Player::setOtherBoard(Board *otherBoard){
    this->otherBoard = otherBoard;
}

Board *Player::getBoard(){
    return &myBoard;
}

void Player::draw(int i){
    for (int j = 0; j < i; j++) {
        deck.moveCardTo(-1, hand);
    }
}

void Player::play(int i, int p, char t) { 
  	shared_ptr<Card> c = hand.getCard(i);
	string cardName = c->getName();
	if (p == 0) { // no targets
		if (cardName == "Raise Dead") {
			if (graveyard.getCardCount() != 0) {
				graveyard.moveCardTo(-1, myBoard);
			}
        } else if (cardName == "Blizzard") {
            c->playCard(myBoard);
			c->playCard(*otherBoard);
            
            for (int j = 0; j < myBoard.getCardCount(); ++j) {
            	if ((myBoard.getCard(j))->getDefense() <= 0) {
					destroyMinion(j);
					--j; // set counter back
				}
			}
			for (int j = 0; j < otherBoard->getCardCount(); ++j) {
				if ((otherBoard->getCard(j)->getDefense()) <= 0) {
					otherPlayer->destroyMinion(j);
					--j; // set counter back
				}
			}
        } else if (cardName == "Recharge") { 
            if (myBoard.getRitual()) {
                c->playCard(myBoard);
            }
        } else if (myBoard.getCardCount() < 5) {
            c->playCard(myBoard);
            State s{*this, Trigger::Summon, myBoard.getCardCount() - 1};
            notifyApnap(s);
        }
    }
    else if (p == player) playTargetCard(c, t);
    else otherPlayer->playTargetCard(c, t);
}

void Player::playTargetCard(shared_ptr<Card> c, char t) {
    int target = t - '0';
    if (t == 'r') target = 0;
    
    string cardName = c->getName();

    if (cardName == "Banish") {
        destroyMinion(target);
    } else if (cardName == "Unsummon") {
        returnToHand(target);
    } else if (cardName == "Disenchant") {
        myBoard.removeEnchant(target);   
    } else {
	shared_ptr<Enchantment> temp_c = dynamic_pointer_cast<Enchantment>(c);
        myBoard.play(temp_c, target); // play enchantment c on target t
    }
}

void Player::attack(int i, int j) {
    std::shared_ptr<Minion> otherMinion = otherBoard->getCard(j - 1);
    std::shared_ptr<Minion> myMinion = myBoard.getCard(i - 1);
    if (j != 0){
        myMinion->attackOther(otherPlayer);
    } else {

        myMinion->attackOther(otherMinion);
    }
    if (myMinion->getDefense() <= 0) destroyMinion(i - 1);
    if (otherMinion->getDefense() <= 0) otherPlayer->destroyMinion(j - 1);
}

void Player::use(int i, int p, int t) {
    shared_ptr<Minion> myMinion = myBoard.getCard(i - 1);
    string cardName = myMinion->getName();
    
    if (name == "Novice Pyromancer") {
        otherBoard->getCard(t - 1)->addStats(0, -1);
        if (otherBoard->getCard(t - 1)->getDefense() <= 0) otherPlayer->destroyMinion(t - 1);
    } else if (name == "Apprentice Summoner" || name == "Master Summoner"){
        if (myBoard.getCardCount() < 5) {
            int limit = 1;
            if (name == "Master Summoner"){
                limit = 3;
            }
            
            while (myBoard.getCardCount() < 5 && limit > 0){
                shared_ptr<Card> c = createCard("Air Elemental");
                c->playCard(myBoard);
                limit -= 1;
            }
        }
    }
}

void Player::discard(int i){
    hand.removeCard(i - 1);
}

/*
std::vector<std::string> Player::displayBoard(){
    Player *p1;
    Player *p2;
    
    if (player == 1){
        p1 = this;
        p2 = otherPlayer;
    }
    else{
        p1 = otherPlayer;
        p2 = this;
    }
    
    int boardHeight = 56;
    int boardLength = 167;
    int cardLength = 33;
    
    std::vector<std::string> display(boardHeight, "");
    display.at(0) = std::string{boardLength, '-'};
    
    card_template_t p2Ritual;
    if (p2->getRitual() != nullptr){
        p2Ritual = p2->getBoard()->getRitual()->displayCard();
    }
    else{
        p2Ritual = CARD_TEMPLATE_EMPTY;
    }
    
    card_template_t p2TopGraveyard;
    if (p2->graveyard.getCardCount == 0){
        p2TopGraveyard = CARD_TEMPLATE_EMPTY;
    }
    else{
        
    }
    
}*/

void Player::destroyMinion(int i) {
    myBoard.moveCardTo(i, graveyard);
    State s{*this, Trigger::Leave, i};
    notifyApnap(s);
}

void Player::returnToHand(int i) {
    myBoard.moveCardTo(i, hand);
}

std::vector<std::string> Player::displayHand(){
    return hand.displayHand();
}

std::vector<std::string> Player::inspectMinion(int i){
    return myBoard.inspect(i);
}
	
void Player::deductMagic(int i, bool testing){
    if (magic - i < 0) {
        if (testing) {
            magic = 0;
        }
    } else {
        magic -= i;
    }
}

int Player::getMagic(){
    return magic;
}
	
void Player::deductLife(int i) {
    life -= i;
}

int Player::getPlayerNumber() {
    return player;
}

int Player::getLife() {
    return life;
}

void Player::notifyApnap(State s) {
    myBoard.notifyObservers(s);
    otherBoard->notifyObservers(s);
}

void Player::runRitual(Ritual &r, State s) {
    string name = r.getName();
    int i = s.index;
    if (name == "Dark Ritual" && s.trigger == Trigger::Begin) {
        ++magic;
        r.activate();
    } else if (name == "Aura of Power" && s.trigger == Trigger::Summon && s.player.getPlayerNumber() == player) {
        myBoard.getCard(i)->addStats(1, 1);
        r.activate();
    } else if (name == "Standstill" && s.trigger == Trigger::Summon) {
        s.player.destroyMinion(i);
        r.activate();
    }
}

//void Player::runTriggerMinion()
