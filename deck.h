#ifndef _DECK_H_
#define _DECK_H_

#include "cardcollection.h"
#include <memory>

class Card;
class Hand;
class Player;

class Deck: public CardCollection {
	public:
	    Deck(std::string deckFile, std::shared_ptr<Player> owner);
    	void shuffle();
        void moveCardTo(int cardPosition, Hand &h) override;
};

#endif
