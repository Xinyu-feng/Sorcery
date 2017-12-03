#include "spell.h"
#include "state.h"

Spell::Spell(std::string name, int manaCost, string description = "") : 
    Card{name, manaCost, description} {}

card_template_t Spell::displayCard() {
	return display_spell(this->getName(), this->getManaCost(),
						this->getDescription());
}
