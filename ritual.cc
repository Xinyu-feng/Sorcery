#include "ritual.h"
#include "subject.h"
#include "player.h"
#include "state.h"

using namespace std;

Ritual::Ritual(std::string name, int manaCost, int charges, int activationCost, string description) : 
    Card{name, manaCost, description}, charges{charges}, activationCost{activationCost} {}

void Ritual::notify(State s) {
    if (active) {
        s.player.runEffect(*this, s);
    }
}

card_template_t Ritual::displayCard() {
	return display_ritual(this->getName(), this->getManaCost(), this->activationCost, this->getDescription(), this->charges);
}

void Ritual::playCard(Board &b, int target){
    b.play(shared_ptr<Ritual>{this});
}

void Ritual::addCharges(int i) { 
    charges += i;
    if (charges < activationCost) {
        active = false;
    } else {
        active = true;
    }
}
void Ritual::addActivateCost(int i) { activationCost += i; }

void Ritual::activate() { addCharges(-activationCost); }