#ifndef _DECK_H_
#define _DECK_H_


#include "cardcollection.h"

class Card;

class Deck: public CardCollection<Card> {
	public:
	void shuffle();
	Card draw();
}

#endif
