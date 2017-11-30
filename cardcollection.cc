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
        collect.addCard(cardList.at(position));
    }
    
	cardList.erase(cardList.begin() + position);
    
}

void CardCollection::addCard(std::shared_ptr<Card> card){
    cardList.emplace_back(card);
}

void CardCollection::setCard(std::shared_ptr<Card> card, int index){
    cardList.at(i) = card;
}

void CardCollection::deleteCard(int index){
    cardList.erase(cardList.begin() + index);
}

std::shared_ptr<Card> CardCollection::getCard(int index){
    return cardList.at(index);
}

int CardCollection::getCardCount(){
    return cardList.size();
}

CardCollection::~CardCollection() {
	this->cardList.clear();
}
