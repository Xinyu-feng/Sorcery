#include "minion.h"

#include <utility>
#include <string>
#include "player.h"

using namespace std;

Minion::Minion(): Card{"", 0, ""} {
	attack = 0;
	defense = 0;
}

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

void Minion::addAction(int i) {
	maxActions += i;
}

void Minion::lowerAction(int i) {
    if (maxActions - i < 0){
        // throw ...
    }
    maxActions -= i;
}

void Minion::setAction(int i) {
    maxActions = i;
}

int Minion::getActions() {
    return maxActions;
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

/*
int Minion::getActivateCost(){
    return activateCost;
}
*/

void Minion::playCard(Board &b, int target){
    b.play(shared_ptr<Minion>{this});
}

/*
void Minion::destroy(Graveyard &g) {
    g.addCard(this);
}
*/

card_template_t Minion::displayCard() {
	return display_minion_no_ability(this->getName(), this->getManaCost(),
									this->getAttack(), this->getDefense());
}
