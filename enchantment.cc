#include <utility>

#include "enchantment.h"
#include "state.h"
#include "board.h"

using namespace std;

Enchantment::Enchantment(string name, int manaCost, string description, string attBuff, string defBuff) : 
    Card{name, manaCost, description}, attBuff{attBuff}, defBuff{defBuff} {}


card_template_t Enchantment::displayCard() {
	// dependent on strings containing + or * symbol
	if (attBuff == "" && defBuff == "") {
		return display_enchantment(this->getName(), this->getManaCost(),
									this->getDescription());
	}
	else {
		return display_enchantment_attack_defence(this->getName(), this->getManaCost(), this->getDescription(), this->attBuff, this->defBuff);
	}
}
