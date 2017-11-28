#ifndef _ENCHANTMENT_H_
#define _ENCHANTMENT_H_

#include "card.h"

class Enchantment: public Card{
    int attackBoost = 0;
    int defenseBoost = 0;
    int attackMultiplier = 0;
    int defenseMultiplier = 0;
    
public:
    Enchantment(std::string name, std::shared_ptr<Player> owner);
    
    void runEffect(Subject &board);
}