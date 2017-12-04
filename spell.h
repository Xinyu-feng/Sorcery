#ifndef _SPELL_H_
#define _SPELL_H_

#include "card.h"

class Spell: public Card {
	
	public:
	
	Spell(std::string name, int manaCost, std::string description = "");
	
	card_template_t displayCard() override;
};

#endif
