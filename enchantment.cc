#include "enchantment.h"

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