#include "abilityminion.h"
#include "subject.h"
#include "minion.h"
#include "state.h"
#include "player.h"
#include "board.h"
#include <utility>

using namespace std;

AbilityMinion::AbilityMinion(string name, int manaCost, int attack, int defence, int abilityCost, string description) : 
    Minion{name, manaCost, attack, defence, description}, abilityCost{abilityCost} {}
    
int AbilityMinion::getAbilityCost() { return abilityCost; }
    
std::vector<card_template_t> AbilityMinion::inspectMinion(){
    return std::vector<card_template_t>{displayCard()};
}

card_template_t AbilityMinion::displayCard() {
	return display_minion_activated_ability(getName(), getManaCost(), getAttack(), 
    	                                    getDefense(), getAbilityCost(), getDescription());
}
