#include "player.h"
#include "minion.h"


Player::Player(int player, std::string name, std::string deckFile):
    	player{player}, name{name}, deck{deckFile, std::shared_ptr<Player>(this)} {
	    
    draw(5);
}


void Player::draw(int i){
    for (int j = 0; j < i; j++) {
        deck.moveCardTo(-1, hand);
    }
}

void Player::play(int i, int p, char t) {
    if (t == '\0' || t > '5' || p != 1 || p != 2) {
        // throw ...
    } else {
        
        int target;
        // t is one of '1', '2', '3', '4', '5', 'r'
        if (t == 'r'){
            target = 0; // ritual located on index 0
        } else {
            target = t;
        }
        Card *c = hand.getCard(i);
        Board b = p == 1 ? myBoard : *otherBoard;
        string cardName = c->getName();
        
        if (cardName == "Banish") {
            hand.removeCard(i);
            b.moveTo(t, graveyard);
        } else if (cardName == "Unsummon") {
            b.moveTo
        }
    }
}

void Player::attack(int i, int j) {
    if (i < 0 || i > 5 || j < 0 || j > 5) {
        // throw ...
    }
    
    std::shared_ptr<Minion> myMinion = myBoard.getCard(i - 1);
    if (j != 0){
        myMinion->attack(otherPlayer);
    } else {
        std::shared_ptr<Minion> otherMinion = otherPlayer->myBoard.getCard(j - 1);
        myMinion->attack(otherMinion);
    }
    if (myMinion->getDefense() <= 0) myBoard.moveCardTo(i - 1, graveyard);
    if (otherMinion.getDefense() <= 0) otherBoard.moveCardTo(j - 1, graveyard)
}

void Player::use(int i, int p, int t) {
}

//std::vector<std::string> displayBoard();
	
void Player::discard(int i){
    hand.discard(i);
}

//std::vector<std::string> displayHand();
	
void Player::deductMagic(int i){
    magic -= i;
    if (magic < 0) magic = 0;
}

int Player::getMagic(){
    return magic;
}
	
void Player::deductLife(int i){
    life -= i;
}

int Player::getLife(){
    return life;
}
