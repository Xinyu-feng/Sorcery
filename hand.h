#ifndef _HAND_H_
#define _HAND_H_

#include "cardcollection.h"

class Hand: public CardCollection{

public:
    void displayHand();
    
    void discard(int i);


}



#endif