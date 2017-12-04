#include "cardcollection.h"
#include "board.h"

using namespace std;

template<typename T>
void CardCollection<T>::moveCardTo(int cardPosition, Hand &h) {}

template<typename T>
void CardCollection<T>::moveCardTo(int cardPosition, Graveyard &g) {}

template<typename T>
void CardCollection<T>::moveCardTo(int cardPosition, Board &b, int target, int defence) {}

template<typename T>
void CardCollection<T>::addCard(std::shared_ptr<T> card){
    cardList.emplace_back(card);
}

template<typename T>
void CardCollection<T>::removeCard(int index) {
    cardList.erase(index);
}

template<typename T>
shared_ptr<T> CardCollection<T>::getCard(int i){
    return cardList.at(i);
}

template<typename T>
void CardCollection<T>::setCard(shared_ptr<T> card, int index){
    cardList.at(index) = card;
}

template<typename T>
int CardCollection<T>::getCardCount(){
    return cardList.size();
}

template<typename T>
CardCollection<T>::~CardCollection() {
	this->cardList.clear();
}