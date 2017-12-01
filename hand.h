#ifndef _HAND_H_
#define _HAND_H_

#include "asciigraphics.h"
#include "cardcollection.h"
#include "card.h"

class Hand: public CardCollection<Card>{

public:
    card_template_t displayHand();
    void discard(int i);
}



#endif
