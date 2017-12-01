#include "cardcollection.h"

void CardCollection::moveCard(CardCollection &collect, int cardPosition) {
    
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

void CardCollection::addCard(std::shared_ptr<Card> card){
    cardList.emplace_back(card);
}

std::shared_ptr<Card> CardCollection::getCard(int i){
    return cardList.at(i);
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
