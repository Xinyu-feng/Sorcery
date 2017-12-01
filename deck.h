#ifndef _DECK_H_
#define _DECK_H_


#include "cardcollection.h"

class Deck: public CardCollection {
	public:
	void shuffle();
	Card draw();
}

#endif
