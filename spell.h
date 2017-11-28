#ifndef _SPELL_H_
#define _SPELL_H_

#include "card.h"

class Spell: public Card{
    
public:
    Spell(std::string name, std::shared_ptr<Player> owner);
    
    void runEffect(Subject &board);
    
    void displayCard();
}

#endif
