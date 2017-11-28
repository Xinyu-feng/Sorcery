#include "ritual.h"
#include "subject.h"
#include "player.h"

Ritual::Ritual(std::string name, std::shared_ptr<Player> owner):Card{name, owner}{
    if (name == "Dark Ritual"){
        charges = 5;
        activationCost = 1;
    }
    else if (name == "Aura of Power"){
        charges = 4;
        activationCost = 1;
    }
    else if (name == "Standstill"){
        charges = 4;
        activationCost = 2;
    }
}

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
}