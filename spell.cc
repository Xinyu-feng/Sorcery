#include "spell.h"
#include "state.h"

Spell::Spell(std::string name, std::shared_ptr<Player> owner, int manaCost, string description = "") : 
    Card{name, owner, manaCost, description} {}

void Spell::runEffect(Subject &board){
    State s = board.getState();
    
    if (name == "Banish"){
        if (s.ritual){
            board.sendToGraveyard('r');
        }
        else{
            board.sendToGraveyard(s.position);
        }
    }
    else if (name == "Unsummon"){
        s.owner->returnToHand(s.position);
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
    else if (name == "Blizzard"){
        int ourMinionCount = board.getMinionCount();
        for (int i = 0; i < ourMinionCount; ++i){
            board.inflictDamage(i, 2);
        }
        
        int theirMinionCount = player->getBoard().getMinionCount();
        for (int i = 0; i < theirMinionCount; ++i){
            player->getBoard().inflictDamage(i, 2);
        }
    }
}