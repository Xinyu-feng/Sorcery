#ifndef _ENCHANTMENT_H_
#define _ENCHANTMENT_H_

#include "card.h"

class Enchantment : public Card {
    
public:
    void runEffect(Subject &board) = 0;
}

#endif