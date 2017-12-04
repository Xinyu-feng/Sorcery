#include "player.h"
#include "minion.h"
#include "state.h"
#include <memory>

using namespace std;

Player::Player(int player, string name, string deckFile, bool doShuffle):
    	player{player}, name{name}, deck{deckFile, doShuffle} {
	    
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
    Card *c = hand.getCard(i);
    string cardName = c->getName();
    if (p == 0) { // no targets
        if (cardName == "Raise Dead") {
            if (graveyard.getSize() != 0) graveyard.moveCardTo(-1, myBoard);
        } else if (cardName == "Blizzard") {
            myBoard.play(c);
            otherBoard.play(c);

            for (int j = 0; j < myBoard.getSize(); ++j) {
                if (myBoard.getCard(j)->getDefence() <= 0) destroyMinion(j--) // minion is erased from cardList and size decreases by one, so counter needs to be set one back
            }
            for (int j = 0; j < otherBoard.getSize(); ++j) {
                if (otherBoard->getCard(j)->getDefence() <= 0) otherPlayer->destroyMinion(j--); // see above for loop
            }
        } else { 
            myBoard.play(c);
            if (c.isMinion()) {
                State s{*this, Trigger::Summon, myBoard.getSize() - 1};
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
    shared_ptr<Minion> myMinion = myBoard.getCard(i - 1);
    if (j != 0){
        myMinion->attack(otherPlayer);
    } else {
        shared_ptr<Minion> otherMinion = otherBoard.getCard(j - 1);
        myMinion->attack(otherMinion);
    }
    if (myMinion->getDefense() <= 0) destroyMinion(i - 1)
    if (otherMinion.getDefense() <= 0) otherPlayer.destroyMinion(j - 1)
}

void Player::use(int i, int p, int t) {
}

//vector<string> displayBoard();

void Player::destroyMinion(int i) {
    myBoard.moveCardTo(i, graveyard);
    State s{*this, Trigger::Leave, i};
    notifyApnap(s);
}

void Player::returnToHand(int i) {
    myBoard.moveCardTo(i, hand);
}

vector<string> Player::displayHand(){
    return hand.displayHand();
}

vector<string> Player::inspectMinion(int i){
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
	/*
	// leave this for mainline logic
    if (life < 0) {
	}
	*/
}
}

int Player::getLife(){
    return life;
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
