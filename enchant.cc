#include "enchant.h"

#include <utility>

Enchant::Enchant(std::shared_ptr<Minion> m, std::shared_ptr<Enchantment> e):MinionDecorator{m}, e{e}{
    if (e.getName() == "Giant Strength"){
        m->addStats(2, 2);
    }
    else if (e.getName() == "Enrage"){
        m->setStats(m.getAttack() * 2, m.getDefense() * 2);
    }
    else if (e.getName() == "Magic Fatigue"){
        m->addAbilityCost(2);
    }
}

void Enchant::runEffect(Subject &b){

    if (e.getName() != "Silence"){
    
        m->runEffect(b);
        
        State s = b->getState();
        
        if (e.getName() == "Haste"){
            if (s.trigger == Trigger::Start){
                addAction(1);
            }
        }
    }
    
}
    