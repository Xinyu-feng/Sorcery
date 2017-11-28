#include "basicminion.h"

#include "subject.h"
#include "minion.h"
#include "state.h"
#include "player.h"
#include "board.h"
#include <utility>

BasicMinion::BasicMinion(std::string name, std::shared_ptr<Player> owner):Minion{name, owner}{
    if (name == "Air Elemental"){
        setStats(1, 1);
    }
    else if (name == "Earth Elemental"){
        setStats(4, 4);
    }
    else if (name == "Bone Golem"){
        setStats(1, 3);
    }
    else if (name == "Fire Elemental"){
        setStats(2, 2);
    }
    else if (name == "Potion Seller"){
        setStats(1, 3);
    }
    else if (name == "Novice Pyromancer"){
        setStats(0, 1);
    }
    else if (name == "Apprentice Summoner"){
        setStats(1, 1);
    }
    else if (name == "Master Summoner"){
        setStats(2, 3);
    }
}

void BasicMinion::runEffect(Subject &board){
    State s = board.getState();
    
    // All activate abilities
    if ((s.trigger == Trigger::Activate) && (getActivateCost() >= getAction())){
        if (name == "Novice Pyromancer"){
            board.inflictDamage(s.position, 1);
        }
        else if (name == "Apprentice Summoner || name == "Master Summoner"){
            // insert details later cuz idk yet
        }
    }
    
    // Triggers
    else if (name == "Bone Golem"){
        if (s.trigger == Trigger::Leave){
            addStats(1, 1);
        }
    }
    
    else if (name == "Fire Elemental"){
        if (s.trigger == Trigger::Summon){
            board.inflictDamage(s.position, 1);
        }
    }
    
    else if (name == "Potion Seller"){
        if (s.trigger == Trigger::End){
            int minionCount = board.getMinionCount();
            for (int i = 0; i < minionCount; ++i){
                board.addDefense(i, 1);
            }
        }
    }
}
            
        