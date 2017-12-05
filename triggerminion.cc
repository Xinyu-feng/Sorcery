#include "triggerminion.h"
#include "observer.h"
#include "minion.h"
#include "state.h"
#include "player.h"
#include "board.h"
#include <utility>

using namespace std;

TriggerMinion::TriggerMinion(string name, int manaCost, int attack, int defence, string description) : 
    Minion{name, manaCost, attack, defence, description} {}
    
std::vector<card_template_t> TriggerMinion::inspectMinion(){
    return std::vector<card_template_t>{displayCard()};
}

card_template_t TriggerMinion::displayCard() {
	return display_minion_triggered_ability(getName(), getManaCost(),
									getAttack(), getDefense(), getDescription());
}

void TriggerMinion::notify(State s) {
    s.player.runTriggerMinion(*this, s);
}