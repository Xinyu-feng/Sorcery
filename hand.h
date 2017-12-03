#ifndef _HAND_H_
#define _HAND_H_

#include "ascii_graphics.h"
#include "cardcollection.h"
#include "card.h"

class Board;
class Graveyard;

class Hand: public CardCollection {
    
	public:
	    card_template_t displayHand();
	    void moveCardTo(int cardPosition, Graveyard &g) override;
	    void moveCardTo(int cardPosition, Board &b, int target = -1) override;
};



#endif
