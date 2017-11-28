#ifndef _RITUAL_H_
#define _RITUAL_H_

#include "card.h"


class Ritual: public Card{
    int charges;
    int activationCost;
    
public:
    Ritual(std::string name, std::shared_ptr<Player> owner);
    
    void runEffect(Subject &board);
    
    void displayCard();
}
