#include <string>
#include <utility>
#include helper.h
#include player.h
#include card.h
#include basicMinion.h
#include spell.h

using namespace std;

Card createCard(string name, shared_ptr<Player> owner) {

    // Spells
    
    if (name == "Banish") {
        Spell newCard{name, owner, 2, "Destroy target minion or ritual"};
    else if (name == "Unsummon") {
        Spell newCard{name, owner, 1, "Return target minion to its owner's hand"};
    }
    else if (name == "Recharge") {
        Spell newCard{name, owner, 1, "Your ritual gains 3 charges"};
    }
    else if (name == "Disenchant") {
        Spell newCard{name, owner, 1, "Destroy the top enchantment on target minion"};
    }
    else if (name == "Raise Dead") {
        Spell newCard{name, owner, 1, "Resurrect the top minion in your graveyard and set its defence to 1"};
    }
    else if (name == "Blizzard") {
        Spell newCard{name, owner, 3, "Deal 2 damage to all minions"};
    }
    
    // Minions
    
    else if (name == "Air Elemental") {
        BasicMinion newCard{name, owner, 0, 1, 1};
    }
    else if (name == "Earth Elemental") {
        BasicMinion newCard{name, owner, 3, 4, 4};
    }
    else if (name == "Bone Golem") {
        TriggerMinion newCard{name, owner, 2, 1, 3, "Gain +1/+1 whenever a minion leaves play"};   
    }
    else if (name == "Fire Elemental") {
        TriggerMinion newCard{name, owner, 2, 2, 2, "Whenever an opponent's minion enters play, deal 1 damage to it"};
    }
    else if (name == "Potion Seller") {
        TriggerMinion newCard{name, owner, 2, 1, 3, "At the end of your turn, all your minions gain +0/+1"};
    }
    else if (name == "Novice Pyromancer") {
        AbilityMinion newCard{name, owner, 1, 0, 1, 1, "Deal 1 damage to target minion"};
    }
    else if (name == "Apprentice Summoner") {
        AbilityMinion newCard{name, owner, 1, 1, 1, 1, "Summon a 1/1 air elemental"};
    }
    else if (name == "Master Summoner") {
        AbilityMinion newCard{name, owner, 3, 2, 3, 2, "Summon up to three 1/1 air elementals"};
    }
    
    // Enchantments
    
    else if (name == "Giant Strength") {
        BuffEnchantment newCard{name, owner, 1, "", "+2", "+2"};
    }
    else if (name == "Enrage") {
        BuffEnchantment newCard{name, owner, 2, "", "*2", "*2"};
    }
    else if (name == "Haste") {
        EffectEnchantment newCard{name, owner, 1, "Enchanted minion gains +1 action each turn"};
    }
    else if (name == "Magic Fatigue") {
        EffectEnchantment newCard{name, owner, 0, "Enchanted minion's activated ability costs 2 more"};
    }
    else if (name == "Silence") {
        EffectEnchantment newCard{name, owner, 1, "Enchanted minion cannot use abilities"};
    }
    
    // Rituals
    
    else if (name == "Dark Ritual") {
        Ritual newCard{name, owner, 0, 5, 1, "At the start of your turn, gain 1 magic"};
    }
    else if (name == "Aura of Power") {
        Ritual newCard{name, owner, 1, 4, 1, "Whenever a minion enters play under your control, it gains +1/+1"};
    }
    else if (name == "Standstill") {
        Ritual newCard{name, owner, 3, 4, 2, "Whenever a minion enters play, destroy it"};
    }
    return newCard;
}