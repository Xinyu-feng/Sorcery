#include "minion.h"

#include <utility>
#include <string>
#include <player.h>

using namespace std;

Minion::Minion(string name, int manaCost, int attack, int defence, string description) :
    Card{name, manaCost, description}, attack{attack}, defence{defence} {}

void Minion::attack(Player *other) {
   /* try { 
        lowerAction(1);
    } catch (...) {
        ...
    } */
    other->reduceLife(attack);
}

void Minion::attack(Minion *other) {
   /* try { 
        lowerAction(1);
    } catch (...) {
        ...
    } */
    addStats(0, -other->getAttack());
    other->addStats(0, -attack);
}

void Minion::lowerAction(int i) {
    if (actions - i < 0){
        // throw ...
    }
    actions -= i;
}

void Minion::setAction(int i) {
    actions = i;
}

int Minion::getActions() {
    return actions;
}

void Minion::addStats(int att, int def) {
    attack += att;
    defence += def;
}

void Minion::setAttack(int i) {
    attack = i;
}

void Minion::setDefense(int i) {
    defense = i;
}
    
void Minion::setStats(int attack, int defense) {
    setAttack(attack);
    setDefense(defense);
}

int Minion::getActivateCost(){
    return activateCost;
}

void Minion::playCard(Board &b, int target){
    b.playMinion(shared_ptr<Minion>{this});
}

void Minion::destroy(Graveyard &g) {
    g.addCard(this);
}

card_template_t Minion::displayCard() {
	return display_minion_no_ability(this->getName(), this->getManaCost(),
									this->getAttack(), this->getDefense());
}
