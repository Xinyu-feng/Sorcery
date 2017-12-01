#include "helper.h"

using namespace std;

shared_ptr<Card> createCard(string name, shared_ptr<Player> owner) {

    shared_ptr<Card> newCard;

    // Spells
    
    if (name == "Banish") {
        newCard = make_shared<Spell>(name, owner, 2, "Destroy target minion or ritual");
	}
    else if (name == "Unsummon") {
        newCard = make_shared<Spell>(name, owner, 1, "Return target minion to its owner's hand");
    }
    else if (name == "Recharge") {
        newCard = make_shared<Spell>(name, owner, 1, "Your ritual gains 3 charges");
    }
    else if (name == "Disenchant") {
        newCard = make_shared<Spell>(name, owner, 1, "Destroy the top enchantment on target minion");
    }
    else if (name == "Raise Dead") {
        newCard = make_shared<Spell>(name, owner, 1, "Resurrect the top minion in your graveyard and set its defence to 1");
    }
    else if (name == "Blizzard") {
        newCard = make_shared<Spell>(name, owner, 3, "Deal 2 damage to all minions");
    }
    
    // Minions
    
    else if (name == "Air Elemental") {
        newCard = make_shared<BasicMinion>(name, owner, 0, 1, 1);
    }
    else if (name == "Earth Elemental") {
        newCard = make_shared<BasicMinion>(name, owner, 3, 4, 4);
    }

	/*
    else if (name == "Bone Golem") {
        newCard = make_shared<TriggerMinion>(name, owner, 2, 1, 3, "Gain +1/+1 whenever a minion leaves play");   
    }
    else if (name == "Fire Elemental") {
        newCard = make_shared<TriggerMinion>(name, owner, 2, 2, 2, "Whenever an opponent's minion enters play, deal 1 damage to it");
    }
    else if (name == "Potion Seller") {
        newCard = make_shared<TriggerMinion>(name, owner, 2, 1, 3, "At the end of your turn, all your minions gain +0/+1");
    }
    else if (name == "Novice Pyromancer") {
        newCard = make_shared<AbilityMinion>(name, owner, 1, 0, 1, 1, "Deal 1 damage to target minion");
    }
    else if (name == "Apprentice Summoner") {
        newCard = make_shared<AbilityMinion>(name, owner, 1, 1, 1, 1, "Summon a 1/1 air elemental");
    }
    else if (name == "Master Summoner") {
        newCard = make_shared<AbilityMinion>(name, owner, 3, 2, 3, 2, "Summon up to three 1/1 air elementals");
    }
    */

    // Enchantments
    
    else if (name == "Giant Strength") {
        newCard = make_shared<Enchantment>(name, owner, 1, "", "+2", "+2");
    }
    else if (name == "Enrage") {
        newCard = make_shared<Enchantment>(name, owner, 2, "", "*2", "*2");
    }
    else if (name == "Haste") {
        newCard = make_shared<Enchantment>(name, owner, 1, "Enchanted minion gains +1 action each turn");
    }
    else if (name == "Magic Fatigue") {
        newCard = make_shared<Enchantment>(name, owner, 0, "Enchanted minion's activated ability costs 2 more");
    }
    else if (name == "Silence") {
        newCard = make_shared<Enchantment>(name, owner, 1, "Enchanted minion cannot use abilities");
    }
    
    // Rituals
    
    else if (name == "Dark Ritual") {
        newCard = make_shared<Ritual>(name, owner, 0, 5, 1, "At the start of your turn, gain 1 magic");
    }
    else if (name == "Aura of Power") {
        newCard = make_shared<Ritual>(name, owner, 1, 4, 1, "Whenever a minion enters play under your control, it gains +1/+1");
    }
    else if (name == "Standstill") {
        newCard = make_shared<Ritual>(name, owner, 3, 4, 2, "Whenever a minion enters play, destroy it");
    }
    return newCard;
}
