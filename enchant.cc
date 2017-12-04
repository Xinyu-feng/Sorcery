#include "enchant.h"

#include <utility>
#include "enchantment.h"
#include "minion.h"
#include "state.h"

using namespace std;

Enchant::Enchant(shared_ptr<AbstractMinion> m, shared_ptr<Enchantment> e) : MinionDecorator{m}, e{e} {}

shared_ptr<AbstractMinion> Enchant::removeEnchant() {
    return getAbstractMinion();
}

int Enchant::getAttack() {
    shared_ptr<AbstractMinion> m = getAbstractMinion();
    if (e->getName() == "Giant Strength") {
        return m->getAttack() + 2;
    } else if (e->getName() == "Enrage") {
        return m->getAttack() * 2;
    }
    return m->getAttack();
}

int Enchant::getDefense() {
    shared_ptr<AbstractMinion> m = getAbstractMinion();
    if (e->getName() == "Giant Strength") {
        return m->getDefense() + 2;
    } else if (e->getName() == "Enrage") {
        return m->getDefense() * 2;
    } 
    return m->getDefense();
}

int Enchant::getActions() {
    shared_ptr<AbstractMinion> m = getAbstractMinion();
    if (e->getName() == "Haste") {
        return m->getActions() + 1;
    } 
    return m->getActions();
}

int Enchant::getAbilityCost() {
    shared_ptr<AbstractMinion> m = getAbstractMinion();
    if (m->getAbilityCost() != -1) {
        if (e->getName() == "Magic Fatigue") {
            return m->getAbilityCost() + 2;
        }
    }
    return m->getAbilityCost();
}

bool Enchant::active() {
    shared_ptr<AbstractMinion> m = getAbstractMinion();
    if (e->getName() == "Silence") {
        return false;
    }
    return m->active();
}
/*
card_template_t Enchant::displayCard() {
	return getAbstractMinion()->displayCard();
}

vector<card_template_t> Enchant::inspectMinion(){
    vector<card_template_t> inspectInfo = getAbstractMinion()->inspectMinion();
    inspectInfo.emplace_back(e->displayCard());
    return inspectInfo;
}
  */  
