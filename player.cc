#include "player.h"
#include "minion.h"
#include "card.h"
#include "enchantment.h"
#include "ritual.h"
#include "triggerminion.h"
#include "abilityminion.h"
#include "helper.h"
#include "board.h"
#include <memory>
#include "ascii_graphics.h"

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

vector<string> Player::displayBoard() {
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
    //int cardLength = 33;
	int cardHeight = 11;
	int middleGraphicHeight = 10;
    
    vector<string> display(boardHeight, "");
    display.at(0) = string(boardLength, '-');
	display.at(boardHeight - 1) = display.at(0);

	vector<string> topMostDisplay = p1->displayBoardRest();
	vector<string> topMidDisplay = p1->displayBoardMinions();
	vector<string> botMidDisplay = p2->displayBoardMinions();
	vector<string> botMostDisplay = p2->displayBoardRest();
	
	for (int i = 0; i < cardHeight; ++i) {
		display.at(i + 1).append("|");
		display.at(i + 1).append(topMostDisplay.at(i));
		display.at(i + 1).append("|");
	}
	for (int i = 0; i < cardHeight; ++i) {
		display.at(i + 1 + cardHeight).append("|");
		display.at(i + 1 + cardHeight).append(topMidDisplay.at(i));
		display.at(i + 1 + cardHeight).append("|");
	}
	for (int i = 0; i < middleGraphicHeight; ++i) {
		display.at(i + 1 + cardHeight * 2).append(CENTRE_GRAPHIC.at(i));
	}
	for (int i = 0; i < cardHeight; ++i) {
		display.at(i + 1 + (cardHeight * 2) + middleGraphicHeight).append("|");
		display.at(i + 1 + (cardHeight * 2) + middleGraphicHeight).append(botMidDisplay.at(i));
		display.at(i + 1 + (cardHeight * 2) + middleGraphicHeight).append("|");
	}
	for (int i = 0; i < cardHeight; ++i) {
		display.at(i + 1 + (cardHeight * 3) + middleGraphicHeight).append("|");
		display.at(i + 1 + (cardHeight * 3) + middleGraphicHeight).append(botMostDisplay.at(i));
		display.at(i + 1 + (cardHeight * 3) + middleGraphicHeight).append("|");
	}
	return display;
}

vector<string> Player::displayBoardRest() {
	int cardHeight = 11;
	vector<string> display(cardHeight, "");
    card_template_t pRitual;
    if (getBoard()->getRitual() != nullptr) {
        pRitual = getBoard()->getRitual()->displayCard();
    }
    else {
        pRitual = CARD_TEMPLATE_BORDER;
    }
    card_template_t pTopGraveyard;
    if (graveyard.getCardCount() == 0){
        pTopGraveyard = CARD_TEMPLATE_BORDER;
    }
    else{
		pTopGraveyard = graveyard.getCard(graveyard.getCardCount() - 1)->displayCard();
    }

	card_template_t pPlayerCard = display_player_card(player, name, getLife(), getMagic());

	for (int i = 0; i < cardHeight; ++i) {
		display.at(i).append(pRitual.at(i));
		display.at(i).append(CARD_TEMPLATE_EMPTY.at(i));
		display.at(i).append(pPlayerCard.at(i));
		display.at(i).append(CARD_TEMPLATE_EMPTY.at(i));
		display.at(i).append(pTopGraveyard.at(i));
	}
	return display;
}

vector<string> Player::displayBoardMinions() {
	int minionCount = myBoard.getCardCount();
	int cardHeight = 11;
	vector<string> display(cardHeight, "");
	for (int i = 0; i < 5; ++i) {
		card_template_t currentCard;
		if (i < minionCount) {
			currentCard = getBoard()->getCard(i)->displayCard();
		}
		else {
			currentCard = CARD_TEMPLATE_BORDER;
		}

		for (int j = 0; j < cardHeight; ++j) {
			display.at(j).append(currentCard.at(j));
		}
	}
	return display;
}

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

void Player::runTriggerMinion(TriggerMinion &tm, State s) {
    string name = tm.getName();
    int i = s.index;
    if (name == "Bone Golem" && s.trigger == Trigger::Leave) {
        tm.addStats(1, 1);
    } else if (name == "Fire Elemental" && s.trigger == Trigger::Summon && s.player.getPlayerNumber() != player) {
        otherBoard->getCard(i)->addStats(0, -1);
    } else if (name == "Potion Seller" && s.trigger == Trigger::End) {
        for (int j = 0; j < myBoard.getCardCount(); ++j) {
            myBoard.getCard(j)->addStats(0, 1);
        }
    }
}
