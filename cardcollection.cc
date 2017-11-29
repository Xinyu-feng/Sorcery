#include "cardcollection.h"

void CardCollection::moveCard(CardCollection &collect, int cardPosition, bool board, int target) {
    
    int position = cardPosition;
    
    if (cardPosition == -1){
        position = getCardCount() - 1;
    }
    
    if (board){
        playCard(cardList.at(position), target);
    }
    else{
        collect.cardList.emplace_back(cardList.at(position));
    }
	cardList.erase(cardList.begin() + position);
    }
}

int CardCollection::getCardCount(){
    return cardList.size();
}

CardCollection::~CardCollection() {
	this->cardList.clear();
}
