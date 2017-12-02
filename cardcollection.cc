#include "cardcollection.h"
#include "board.h"

template<typename T>

class Board;


void CardCollection::moveCard(CardCollection<Card> &collect, int cardPosition) {
    
    int position = cardPosition;
    
    if (cardPosition == -1){
        position = getCardCount() - 1;
    }

    collect.addCard(cardList.at(position));
    
	cardList.erase(cardList.begin() + position);
    
}

void CardCollection::moveCardtoBoard(Board &b, int cardPosition, int target){
    int position = cardPosition;
    
    if (cardPosition == -1){
        position = getCardCount() - 1;
    }
    cardList.at(position).play(b, target);

    cardList.erase(cardList.begin() + position);
}

void CardCollection::addCard(std::shared_ptr<T> card){
    cardList.emplace_back(card);
}

std::shared_ptr<T> CardCollection::getCard(int i){
    return cardList.at(i);
}

void CardCollection::setCard(std::shared_ptr<T> card, int index){
    cardList.at(i) = card;
}

void CardCollection::deleteCard(int index){
    cardList.erase(cardList.begin() + index);
}

int CardCollection::getCardCount(){
    return cardList.size();
}

CardCollection::~CardCollection() {
	this->cardList.clear();
}
