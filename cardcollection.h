#ifndef _CARD_COLLECTION_H_
#define _CARD_COLLECTION_H_


#include <memory>
#include <vector>

class Card;

class CardCollection {
	std::vector <std::shared_ptr<Card>> cardList;
public:


    // This function moves a card to the collect CardCollection
    // cardPosition represents the position of the card in the deck
    // Default value -1 indicates you want the top card
    
	void moveCard(CardCollection &collect, int cardPosition = -1);
	void moveCardToBoard(Board &b, int cardPosition = -1, target = -1);
	
	virtual void addCard(std::shared_ptr<Card> card);
	std::shared_ptr<Card> getCard(int i);
	
	void setCard(std::shared_ptr<Card> card, int index);
	void deleteCard(int index);
	
	std::shared_ptr<Card> CardCollection::getCard(int index);
	
	int getCardCount();
	virtual ~CardCollection() = 0;
};


#endif