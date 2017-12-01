#include "enchantment.h"
#include <utility>
#include "state.h"

using namespace std;

Enchantment::Enchantment(string name, shared_ptr<Player> owner, int manaCost, string description, string attBuff, string defBuff) : 
    Card{name, owner, manaCost, description}, attBuff{attBuff}, defBuff{defBuff} {}

void Enchantment::runEffect(State s){...} // move to helper function

void Enchantment::playCard(Board &b, int target){
    b.playEnchant(std::shared_ptr<Enchantment>{this}, target);
}

card_template_t Enchantment::displayCard() {
	if (attBuff == "" && defBuff == "") {
		return display_enchantment(this->getName(), this->getManaCost(),
									this->getDescription());
	}
	else {
		return display_enchantment_attack_defence(this->getName(), this->getManaCost(), this->getDescription(), this->attBuff, this->defBuff);
	}
}
