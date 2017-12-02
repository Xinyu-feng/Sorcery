#ifndef _CARD_COLLECTION_H_
#define _CARD_COLLECTION_H_

#include <memory>
#include <vector>

class Board;
class Card;

template<typename T> class CardCollection {
	std::vector <std::shared_ptr<T>> cardList;
public:


    // This function moves a card to the collect CardCollection
    // cardPosition represents the position of the card in the deck
    // Default value -1 indicates you want the top card
    
	void moveCard(CardCollection<Card> &collect, int cardPosition = -1);
	void moveCardToBoard(Board &b, int cardPosition = -1, int target = -1);
	
	virtual void addCard(std::shared_ptr<T> card);
	std::shared_ptr<T> getCard(int i);
	
	void setCard(std::shared_ptr<T> card, int index);
	void deleteCard(int index);
	
	int getCardCount();
	virtual ~CardCollection() = 0;
};


#endif
