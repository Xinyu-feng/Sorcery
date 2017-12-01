#ifndef _HAND_H_
#define _HAND_H_

#include "cardcollection.h"
#include "card.h"

class Card;

class Hand: public CardCollection<Card>{

public:
    void displayHand();
    void discard(int i);
}



#endif