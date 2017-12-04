#ifndef _CARD_COLLECTION_H_
#define _CARD_COLLECTION_H_

#include <memory>
#include <vector>


class Board;
class Card;
class Deck;
class Graveyard;
class Hand;

template<typename T> class CardCollection {
	protected:
	std::vector <std::shared_ptr<T>> cardList;
	public:
	    
	virtual void moveCardTo(int cardPosition, Hand &h);
	virtual void moveCardTo(int cardPosition, Graveyard &g);
	// -1 indicates you want the top card
	virtual void moveCardTo(int cardPosition, Deck &d);
	virtual void moveCardTo(int cardPosition, Board &b, int target = -1);

	void addCard(std::shared_ptr<T> card);
	void removeCard(int index);
	std::shared_ptr<T> getCard(int i);
	
	void setCard(std::shared_ptr<T> card, int index);
    	virtual void discard(int index);
	
    	int getCardCount();
    	virtual ~CardCollection() = 0;
};

#include "card.h"
#include "hand.h"
#include "graveyard.h"
#include "deck.h"

template <typename T>
void CardCollection<T>::addCard(std::shared_ptr<T> card){
    cardList.emplace_back(card);
}

template <typename T>
void CardCollection<T>::removeCard(int index) {
    cardList.erase(index);
}

template <typename T>
void CardCollection<T>::moveCardTo(int cardPosition, Graveyard &g) {
    cardList.at(cardPosition)->destroy(g);
    cardList.erase(cardList.begin() + cardPosition);
}

template <typename T>
std::shared_ptr<T> CardCollection<T>::getCard(int i){
    return cardList.at(i);
}

template <typename T>
void CardCollection<T>::setCard(std::shared_ptr<T> card, int index){
    cardList.at(index) = card;
}

template <typename T>
int CardCollection<T>::getCardCount(){
    return cardList.size();
}

template <typename T>
CardCollection<T>::~CardCollection() {
	this->cardList.clear();
}





#endif
