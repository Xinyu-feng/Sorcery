#ifndef _ENCHANTMENT_H_
#define _ENCHANTMENT_H_

#include "card.h"

class Enchantment : public Card {
    std::string attBuff;
    std::string defBuff;
public:
    Enchantment(std::string name, int manaCost, std::string description = "", std::string attBuff = "", std::string defBuff = "");
    
    void playCard(Board &b, int target = -1) override;

    card_template_t displayCard() override;
};

#endif
