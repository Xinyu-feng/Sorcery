#include "enchant.h"

#include <utility>
#include "enchantment.h"
#include "minion.h"
#include "subject.h"
#include "state.h"

Enchant::Enchant(std::shared_ptr<Minion> m, std::shared_ptr<Enchantment> e):MinionDecorator{m}, e{e}{
	std::string enchantName = e->getName();
    if (enchantName == "Giant Strength"){
        getMinion()->addStats(2, 2);
    }
    else if (enchantName == "Enrage"){
        getMinion()->setStats(m->getAttack() * 2, m->getDefense() * 2);
    }
    else if (enchantName == "Magic Fatigue"){
        //getMinion()->addAbilityCost(2);
    }
}

/*
void Enchant::runEffect(Subject &b){
	
    if (e.getName() != "Silence"){
    
        getMinion()->runEffect(b);
        
        State s = b->getState();
        if (e.getName() == "Haste"){
            if (s.trigger == Trigger::Start){
                addAction(1);
            }
        }
    }
}
*/

std::shared_ptr<Minion> Enchant::removeEnchant() {
	std::string enchantName = e->getName();
    if (enchantName == "Giant Strength"){
        getMinion()->addStats(-2, -2);
    }
    else if (enchantName == "Enrage"){
        getMinion()->setStats(getMinion()->getAttack() / 2, getMinion()->getDefense() / 2);
    }
    else if (enchantName == "Magic Fatigue"){
        //getMinion()->lowerAbilityCost(2);
    }
    
    return getMinion();
}

card_template_t Enchant::displayCard() {
	return getMinion()->displayCard();
}

std::vector<card_template_t> Enchant::inspectMinion(){
    std::vector<card_template_t> inspectInfo = getMinion()->inspectMinion();
    inspectInfo.emplace_back(e->displayCard());
    return inspectInfo;
}
    
