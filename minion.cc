#include "minion.h"

#include <utility>
#include <string>
#include "player.h"

using namespace std;

Minion::Minion(string name, int manaCost, int attack, int defense, string description) :
    Card{name, manaCost, description}, attack{attack}, defense{defense} {}

void Minion::attackOther(Player * other) {
   /* try { 
        lowerAction(1);
    } catch (...) {
        ...
    } */
    other->deductLife(attack);
}

void Minion::attackOther(shared_ptr<Minion> other) {
   /* try { 
        lowerAction(1);
    } catch (...) {
        ...
    } */
    addStats(0, -other->getAttack());
    other->addStats(0, -attack);
}

void Minion::lowerAction(int i) {
    currActions -= i;
}

void Minion::setAction(int i) {
    currActions = i;
}

int Minion::getActions() {
    return currActions;
}

void Minion::resetActions() {
    currActions = 1;
}

void Minion::addStats(int att, int def) {
    attack += att;
    defense += def;
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

int getAttack() { return attack; }
int getDefense() { return defence; }
int getAbilityCost() { return -1; } // no ability
bool active() { return false; } // no ability


/*
int Minion::getActivateCost(){
    return activateCost;
}
*/

void Minion::playCard(Board &b, int target){
    b.play(shared_ptr<Minion>{this});
}


card_template_t Minion::displayCard() {
	return display_minion_no_ability(this->getName(), this->getManaCost(),
									this->getAttack(), this->getDefense());
}

bool isMinion() { return true; }