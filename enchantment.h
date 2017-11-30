#ifndef _ENCHANTMENT_H_
#define _ENCHANTMENT_H_

#include "card.h"

class Enchantment : public Card {
    
public:
    Enchantment(std::string name, std::shared_ptr<Player> owner, int manaCost, string description = "");
    
    void runEffect(Subject &board);
}