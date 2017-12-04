#include "enchant.h"

#include <utility>
#include "enchantment.h"
#include "minion.h"
#include "state.h"

using namespace std;

Enchant::Enchant(shared_ptr<AbstractMinion> m, shared_ptr<Enchantment> e) : MinionDecorator{m}, e{e} {}

shared_ptr<Minion> Enchant::removeEnchant() {
    getMinion();
}

int Enchant::getAttack() {
    Minion &m = getMinion();
    if (e->getName() == "Giant Strength") {
        return m->getAttack() + 2;
    } else if (e->getName() == "Enrage") {
        return m->getAttack() * 2;
    }
    return m->getAttack();
}

int Enchant::getDefence() {
    Minion &m = getMinion();
    if (e->getName() == "Giant Strength") {
        return m->getDefence() + 2;
    } else if (e->getName() == "Enrage") {
        return m->getDefence() * 2;
    } 
    return m->getDefence();
}

int Enchant::getActions() {
    Minion &m = getMinion();
    if (e->getName() == "Haste") {
        return m->getActions() + 1;
    } 
    return m->getActions();
}

int Enchant::getAbilityCost() {
    Minion &m = getMinion();
    if (m->getAbilityCost() != -1) {
        if (e->getName() == "Magic Fatigue") {
            return m->getAbilityCost() + 2;
        }
    }
    return m->getAbilityCost();
}

bool Enchant::active {
    Minion &m = getMinion();
    if (e->getName() == "Silence") {
        return false;
    }
    return m->active();
}

card_template_t Enchant::displayCard() {
	return getMinion()->displayCard();
}

std::vector<card_template_t> Enchant::inspectMinion(){
    std::vector<card_template_t> inspectInfo = getMinion()->inspectMinion();
    inspectInfo.emplace_back(e->displayCard());
    return inspectInfo;
}
    
