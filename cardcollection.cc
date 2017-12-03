#include "cardcollection.h"
#include "board.h"

class Board;

void CardCollection::addCard(std::shared_ptr<Card> card){
    cardList.emplace_back(card);
}

void CardCollection::removeCard(int index) {
    cardList.erase(index);
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
