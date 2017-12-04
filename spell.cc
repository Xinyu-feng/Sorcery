#include "spell.h"
#include "state.h"
#include "board.h"

using namespace std;

Spell::Spell(string name, int manaCost, string description) : 
    Card{name, manaCost, description} {}

// this code was moved to player.cc
void playCard(Board &b, int target = -1) {
	/*
    string name = getName();
    shared_ptr<Card> t;
    if (target != -1) {
		t = b.getCard(target);
	}
    
    if (name == "Banish"){
        if (b.ritual){
            board.sendToGraveyard('r');
        }
        else{
            board.sendToGraveyard(b.position);
        }
    }
    else if (name == "Unsummon"){
		b->returnToHand(s.position);
    }
    else if (name == "Recharge"){
        s.card->addCharge(3);
    }
    else if (name == "Disenchant"){
        s.card->removeEnchant();
    }
    else if (name == "Raise Dead"){
        board.reviveMonster();
    }
    else if (name == "Blizzard") {
		// this code should be called on both boards
        int ourMinionCount = board.getMinionCount();
        for (int i = 0; i < ourMinionCount; ++i){
            board.inflictDamage(i, 2);
        }
        
        int theirMinionCount = player->getBoard().getMinionCount();
        for (int i = 0; i < theirMinionCount; ++i){
            player->getBoard().inflictDamage(i, 2);
        }
		
    }
	*/
}

card_template_t Spell::displayCard() {
	return display_spell(this->getName(), this->getManaCost(),
						this->getDescription());
}
