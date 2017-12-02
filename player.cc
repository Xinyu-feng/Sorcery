#include "player.h"



Player::Player(int player, std::string name, std::string deckFile, bool shuffle, int life, int magic):
		player{player}, name{name}, deck{deckFile, std::shared_ptr<Player>(this), shuffle}, life{life}, magic{magic} {
    
	if (shuffle) deck.shuffle();
    
    for (int i = 0; i < 5; ++i) draw();
}


void Player::draw(){
    deck.moveCard(hand);
}

void Player::play(int i, int p, char t){
    int target;
    
    // Index on board for ritual is located at 0
    if (t == 'r'){
        target = 0;
    }
    // If still default value, make sure it's -1
    else if (t == '\0'){
        target = -1;
    }
    // Convert char index into int from 1 to 5
    else{
        target = 'a' - t;
    }
    

    if (p == 1){
        hand.moveCardToBoard(myBoard, i - 1, target);
    }
    else{
        hand.moveCardToBoard(*otherBoard, i - 1, target);
    }
}

void Player::attack(int i, int j){
    if (j == 0){
        // Insert direct attack code
    }
    
    else{
        std::shared_ptr<Minion> myMinion = myBoard.getCard(i - 1);
        std::shared_ptr<Minion> otherMinion = otherBoard->getCard(j - 1);
        
        myMinion->lowerAction(1);
        otherMinion->addStats(0, -myMinion->getAttack());
        
        if (otherMinion->getDefense() == 0){
            //otherBoard->sendToGraveyard(j - 1);
        }
        
        else{
            myMinion->addStats(0, -otherMinion->getAttack());
            if (myMinion->getDefense() == 0){
                //myBoard.sendToGraveyard(i - 1);
            }
        }
    }
}


void Player::use(int i, int p, int t) {
}

//std::vector<std::string> displayBoard();
	
void Player::discard(int i){
    hand.discard(i);
}

//std::vector<std::string> displayHand();
	
void Player::addMagic(int i){
    magic += i;
}

void Player::deductMagic(int i){
    magic -= i;
    if (magic < 0) magic = 0;
}

int Player::getMagic(){
    return magic;
}
	
void Player::addLife(int i){
    life += i;
}
void Player::deductLife(int i){
    life -= i;
    if (life < 0) life = 0;
}

int Player::getLife(){
    return life;
}
