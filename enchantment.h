#ifndef _ENCHANTMENT_H_
#define _ENCHANTMENT_H_

#include "card.h"

class Enchantment : public Card {
    std::string attBuff;
    std::string defBuff;
public:
    Enchantment(std::string name, std::shared_ptr<Player> owner, int manaCost, std::string description = "", std::string attBuff = "", std::string defBuff = "");
    void runEffect(Subject &board);
    
    void playCard(Board &b, int target = -1);
}

#endif