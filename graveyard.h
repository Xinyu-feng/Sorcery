#ifndef _GRAVEYARD_H_
#define _GRAVEYARD_H_

#include "cardcollection.h"

class Minion;

class Graveyard: public CardCollection<Minion> {
	public:
    	void moveCardTo(int cardPosition, Hand &h) override;
    	void moveCardTo(int cardPosition, Board &b, int defence = 1, int target = -1) override;
};

#endif
