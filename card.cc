#include "card.h"
#include "subject.h"
#include "state.h"

Card::Card(std::string name, std::shared_ptr<Player> owner):name{name}, owner{owner}{
    
    // Spell Cards
    if (name == "Banish"){
        manaCost = 2;
        description = "Destroy target minion or ritual";
    }
    else if (name == "Unsummon"){
        manaCost = 1;
        description = "Return target minion to its owner's hand";
    }
    else if (name == "Recharge"){
        manaCost = 1;
        description = "Your ritual gains 3 charges";
    }
    else if (name == "Disenchant"){
        manaCost = 1;
        description = "Destroy the top enchantment on target minion";
    }
    else if (name == "Raise Dead"){
        manaCost = 1;
        description = "Resurrect the top minion in your graveyard and set its defence to 1";
    }
    else if (name == "Blizzard"){
        manaCost = 3;
        description = "Deal 2 damage to all minions";
    }
    
    // Minions
    
    else if (name == "Air Elemental"){
        manaCost = 0;
    }
    else if (name == "Earth Elemental"){
        manaCost = 3;
    }
    else if (name == "Bone Golem"){
        manaCost = 2;
        description = "Gain +1/+1 whenever a minion leaves play.";   
    }
    else if (name == "Fire Elemental"){
        manaCost = 2;
        description = "Whenever an opponent's minion enters play, deal 1 damage to it";
    }
    else if (name == "Potion Seller"){
        manaCost = 2;
        description = "At the end of your turn, all your minions gain +0/+1";
    }
    else if (name == "Novice Pyromancer"){
        manaCost = 1;
        description = "Deal 1 damage to target minion";
    }
    else if (name == "Apprentice Summoner"){
        manaCost = 1;
        description = "Summon a 1/1 air elemental";
    }
    else if (name == "Master Summoner"){
        manaCost = 3;
        description = "Summon up to three 1/1 air elementals";
    }
    
    // Enchantments
    
    else if (name == "Giant Strength"){
        manaCost = 1;
    }
    else if (name == "Enrage"){
        manaCost = 2;
    }
    else if (name == "Haste"){
        manaCost = 1;
        description = "Enchanted minion gains +1 action each turn";
    }
    else if (name == "Magic Fatigue"){
        manaCost = 0;
        description = "Enchanted minion's activated ability costs 2 more";
    }
    else if (name == "Silence"){
        manaCost = 1;
        description = "Enchanted minion cannot use abilities";
    }
    
    // Rituals
    
    else if (name == "Dark Ritual"){
        manaCost = 0;
        description = "At the start of your turn, gain 1 magic";
    }
    else if (name == "Aura of Power"){
        manaCost = 1;
        description = "Whenever a minion enters play under your control, it gains +1/+1";
    }
    else if (name == "Standstill"){
        manaCost = 3;
        description = "Whenever a minion enters play, destroy it";
    }
}

void Card::notify(Subject &whoFrom){
	runEffect(whoFrom);
}

void Card::getManaCost(){
    return manaCost;
}
