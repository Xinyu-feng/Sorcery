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

        if (p == 1){
            //rewrite w/ moveCardTo
            hand.moveCardToBoard(myBoard, i - 1, target);
        }
        else{
            //rewrite w/ moveCardTo
            hand.moveCardToBoard(*otherBoard, i - 1, target);
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
