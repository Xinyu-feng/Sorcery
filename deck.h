#ifndef _DECK_H_
#define _DECK_H_


#include "cardcollection.h"

class Card;
class Player;

class Deck: public CardCollection<Card> {
	public:
	    Deck(std::string deckFile, std::shared_ptr<Player> owner);
    	void shuffle();
    	std::shared_ptr<Card> draw();
};

#endif
