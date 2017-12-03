#include "player.h"
#include "minion.h"


Player::Player(int player, std::string name, std::string deckFile, bool shuffle):
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
    if (t == '\0' || t > '5' || p != 1 || p != 2) {
        // throw ...
    } else {

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
                for (int j = 0; j < otherBoard.getSize(); j++) {
                    if (otherBoard.getCard(j)->getDefence() <= 0) otherPlayer->destroyMinion(j--); // see above for loop
                }
            } else { 
                myBoard.play(c);
            }
        }
        else if (p == player) playTargetCard(c, t);
        else otherPlayer->playTargetCard(c, t);
    }
}

void Player::playTargetCard(Card *c, int t) {
    string cardName = c->getName();
    if (cardName == "Banish") {
        destroyMinion(t);
    } else if (cardName == "Unsummon") {
        returnToHand(t);
    } else if (cardName == "Disenchant") {
        myBoard.removeEnchant(t);   
    } else {
        myBoard.play(c, t); // play enchantment c on target t
    }
}

void Player::attack(int i, int j) {
    std::shared_ptr<Minion> myMinion = myBoard.getCard(i - 1);
    if (j != 0){
        myMinion->attack(otherPlayer);
    } else {
        std::shared_ptr<Minion> otherMinion = otherBoard.getCard(j - 1);
        myMinion->attack(otherMinion);
    }
    if (myMinion->getDefense() <= 0) destroyMinion(i - 1)
    if (otherMinion.getDefense() <= 0) otherPlayer.destroyMinion(j - 1)
}

void Player::use(int i, int p, int t) {
}

//std::vector<std::string> displayBoard();

void Player::destroyMinion(int i) {
    board.moveCardTo(i, graveyard);
    board.notifyObservers(); // state should be Destroyed
}

void Player::returnToHand(int i) {
    board.moveCardTo(i, hand);
}

std::vector<std::string> Player::displayHand(){
    return hand.displayHand();
}

std::vector<std::string> Player::inspectMinion(int i){
    return myBoard.inspectMinion(i);
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

int Player::getLife(){
    return life;
}
