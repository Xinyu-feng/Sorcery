#include "cardcollection.h"

void CardCollection::moveCard(int i, CardCollection &collect) {
	collect.cardList.emplace_back(cardList.at(i));
}

int CardCollection::getCardCount(){
    return cardList.size();
}

CardCollection::~CardCollection() {
	this->cardList.clear();
}
