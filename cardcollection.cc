#include "cardcollection.h"
#include "board.h"

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

void CardCollection::addCard(Card *card){
    cardList.emplace_back(card);
}

void Hand::moveCardTo(int cardPosition, Graveyard &g) {
    cardList.at(cardPosition)->destroy(g);
    cardList.erase(cardList.begin() + i);
}

shared_ptr<Card> CardCollection::getCard(int i){
    return cardList.at(i);
}

void CardCollection::setCard(std::shared_ptr<Card> card, int index){
    cardList.at(i) = card;
}

int CardCollection::getCardCount(){
    return cardList.size();
}

CardCollection::~CardCollection() {
	this->cardList.clear();
}
