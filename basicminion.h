#ifndef _BASICMINION_H_
#define _BASICMINION_H_

#include "minion.h"

class BasicMinion: public Minion {

public:
    BasicMinion(std::string name, int manaCost, int attack, int defence, std::string description = "");
    
    card_template_t displayCard() override;
    std::vector<card_template_t> inspectMinion() override;    
};


#endif
