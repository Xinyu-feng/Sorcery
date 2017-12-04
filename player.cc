#include "player.h"
#include "minion.h"
#include "card.h"
#include "enchantment.h"
#include "ritual.h"
#include <memory>

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

void Player::play(int i, int p, char t) { // have this remove magic
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
        } else { 
            c->playCard(myBoard);
            if (c.isMinion()) {
                State s{*this, Trigger::Summon, myBoard.getCardCount() - 1};
                notifyApnap(s);
            }
        }
    }
    else if (p == player) playTargetCard(c, t);
    else otherPlayer->playTargetCard(c, t);
}

void Player::playTargetCard(shared_ptr<Card> c, int t) {
    int target = t - "0";
    if (t == "r") target = 0;
    
    string cardName = c->getName();
    if (cardName == "Banish") {
        destroyMinion(t);
    } else if (cardName == "Unsummon") {
        returnToHand(t);
    } else if (cardName == "Disenchant") {
        myBoard.removeEnchant(t);   
    } else {
		shared_ptr<Enchantment> temp_c = dynamic_pointer_cast<Enchantment>(c);
        myBoard.play(temp_c, t); // play enchantment c on target t
    }
}

void Player::attack(int i, int j) {
    std::shared_ptr<Minion> myMinion = myBoard.getCard(i - 1);
    if (j != 0){
        myMinion->attackOther(otherPlayer);
    } else {
        std::shared_ptr<Minion> otherMinion = otherBoard.getCard(j - 1);
        myMinion->attackOther(otherMinion);
    }
    if (myMinion->getDefense() <= 0) destroyMinion(i - 1)
    if (otherMinion.getDefense() <= 0) otherPlayer.destroyMinion(j - 1)
}

void Player::use(int i, int p, int t) {
}

//std::vector<std::string> displayBoard();

void Player::destroyMinion(int i) {
    board.moveCardTo(i, graveyard);
    State s{*this, Trigger::Leave, i};
    notifyApnap(s);
}

void Player::returnToHand(int i) {
    board.moveCardTo(i, hand);
}

std::vector<std::string> Player::displayHand(){
    return hand.displayHand();
}

std::vector<std::string> Player::inspectMinion(int i){
    return myBoard.inspect(i);
}
	
void Player::deductMagic(int i, bool testing){
    if (magic - i < 0 && !testing) // throw;
    magic -= i;
}

int Player::getMagic(){
    return magic;
}
	
void Player::deductLife(int i){
    life -= i;
    if (life < 0) // i lose
}

int Player::getLife() {
    life -= i;
}

void notifyApnap(State s) {
    myBoard.notifyObservers(s);
    otherBoard->notifyObservers(s);
}

void runEffect(Card &c, State s) {
    if (name == "Dark Ritual" && s.trigger == Trigger::Begin) {
        ++magic;
        c.activate();
    } else if (name == "Aura of Power" && s.trigger == Trigger::Summon && s.player = *this) {
        myBoard.getCard(i).addStats(1, 1);
        c.activate();
    } else if (name == "Standstill" && s.trigger == Trigger::Summon) {
        s.player.destroyMinion(i);
        c.activate();
    } else {
        //...
    }
}