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
	// virtual void moveCardTo(int cardPosition, Deck &d); currently no cards use this
	virtual void moveCardTo(int cardPosition, Board &b, int target = -1);
	
	void addCard(std::shared_ptr<T> card);
	void removeCard(int index);
	std::shared_ptr<T> getCard(int i);
	
	void setCard(std::shared_ptr<T> card, int index);
    virtual void discard(int index);
	
    int getCardCount();
    virtual ~CardCollection() = 0;
};

#endif