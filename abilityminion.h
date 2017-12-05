#ifndef _ABILITYMINION_H_
#define _ABILITYMINION_H_

#include "minion.h"

class AbilityMinion: public Minion {
    int abilityCost;
public:
    AbilityMinion(std::string name, int manaCost, int attack, int defence, int abilityCost std::string description = "");
    
    int getAbilityCost() override;
    
    card_template_t displayCard() override;
    std::vector<card_template_t> inspectMinion() override;    
};
#endif