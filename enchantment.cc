#include "enchantment.h"
#include <utility>
#include "state.h"

Enchantment::Enchantment(std::string name, std::shared_ptr<Player> owner):Card{name, owner}{
    if (name == "Giant Strength"){
        attackBoost = 2;
        defenseBoost = 2;
    }
    else if (name == "Enrage"){
        attackMultiplier = 2;
        defenseMultiplier = 2;
    }
}

void Enchantment::runEffect(State s){ return void;}