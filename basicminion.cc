#include "basicminion.h"

#include "subject.h"
#include "minion.h"
#include "state.h"
#include "player.h"
#include "board.h"
#include <utility>

using namespace std;

BasicMinion::BasicMinion(string name, shared_ptr<Player> owner, int manaCost, int attack, int defence, string description) : 
    Minion{name, owner, manaCost, attack, defence, description} {}
/*
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
            
        */