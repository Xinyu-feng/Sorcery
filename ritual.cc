#include "ritual.h"
#include "subject.h"
#include "player.h"

using namespace std;

Ritual::Ritual(string name, int manaCost, int charges, int activationCost, string description) : 
    Card{name, manaCost, description}, charges{charges}, activationCost{activationCost} {}

/*

void Ritual::runEffect(Subject &board){
    State s = board.getState();
    if (charges >= activationCost){
        if (name == "Dark Ritual"){
            if (s.owner == owner && s.trigger == Trigger::Begin){
                owner->addMagic(1);
                charges -= activationCost;
            }
        }
        else if (name == "Aura of Power"){
            if (s.owner == owner && s.trigger == Trigger::Summon){
                s.card->changeAttack(1);
                s.card->changeDefense(1);
                charges -= activationCost;
            }
        }
        else if (name == "Standstill"){
            if (s.trigger == Trigger::Summon){
                board.sendToGrave(s.position);
                charges -= activationCost;
            }
        }
    }
}*/

void Ritual::playCard(Board &b, int target){
    b.play(shared_ptr<Ritual>{this});
}

card_template_t Ritual::displayCard() {
	return display_ritual(this->getName(), this->getManaCost(), this->activationCost, this->getDescription(), this->charges);
}

void Ritual::addCharges(int i) { charges += i; }
void Ritual::addActivateCost(int i) { activationCost += i; }
