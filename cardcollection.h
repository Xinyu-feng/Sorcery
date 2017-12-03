#ifndef _CARD_COLLECTION_H_
#define _CARD_COLLECTION_H_

#include <memory>
#include <vector>

class Board;
class Card;
class Deck;
class Graveyard;
class Hand;

class CardCollection {
    protected:
    	std::vector <std::shared_ptr<Card>> cardList;
    public:


        // This function moves a card to the collect CardCollection
        // cardPosition represents the position of the card in the deck

    
	    virtual void moveCardTo(int cardPosition, Hand &h);
	    virtual void moveCardTo(int cardPosition, Graveyard &g);
	   // -1 indicates you want the top card
	    virtual void moveCardTo(int cardPosition, Deck &d);
	    virtual void moveCardTo(int cardPosition, Board &b, int target = -1);
	
	    void addCard(const Card &card);
	    void removeCard(int index);
    	std::shared_ptr<Card> getCard(int i);
	
    	void setCard(std::shared_ptr<Card> card, int index);
    	virtual void discard(int index);
	
    	int getCardCount();
    	virtual ~CardCollection() = 0;
};


#endif
