#include "cardcollection.h"
#include "board.h"

using namespace std;

void CardCollection<T>::moveCardTo(int cardPosition, Hand &h) {}

void CardCollection<T>::moveCardTo(int cardPosition, Graveyard &g) {}

void CardCollection<T>::moveCardTo(int cardPosition, Board &b, int target, int defence) {}

void CardCollection<T>::addCard(std::shared_ptr<T> card){
    cardList.emplace_back(card);
}

void CardCollection<T>::removeCard(int index) {
    cardList.erase(index);
}


shared_ptr<T> CardCollection<T>::getCard(int i){
    return cardList.at(i);
}

void CardCollection<T>::setCard(shared_ptr<T> card, int index){
    cardList.at(index) = card;
}

int CardCollection<T>::getCardCount(){
    return cardList.size();
}

CardCollection<T>::~CardCollection() {
	this->cardList.clear();
}