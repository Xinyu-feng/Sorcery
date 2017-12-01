#include "deck.h"

#include "card.h"
#include "spell.h"
#include "enchantment.h"
#include "ritual.h"
#include "basicminion.h"

#include <string>
#include <ifstream>
#include <cstdlib>
#include <memory>


const std::vector<std::string> minions = {"Air Elemental", "Earth Elemental", "Bone Golem", "Fire Elemental", "Potion Seller", "Novice Pyromancer", "Apprentice Summoner", "Master Summoner"};
const std::vector<std::string> spells = {"Banish", "Unsummon", "Recharge", "Disenchant", "Raise Dead", "Blizzard"};
const std::vector<std::string> enchantments = {"Giant Strength", "Enrage", "Haste", "Magic Fatigue", "Silence"};
const std::vector<std::string> rituals = {"Dark Ritual", "Aura of Power", "Standstill"};



bool inVector(std::vector<std::string> &v, std::string s){
    int length = v.size();
    for (int i = 0; i < length; ++i){
        if (v.at(i) == s){
            return true;
        }
    }
    return false;
}


Deck::Deck(std::string deckFile, std::shared_ptr<Player> owner, bool shuffle){
    std::ifstream deck{deckFile};
    
    deck.open();
    
    std::string cardName;
    
    while(deck.getline(cardName)){
        if (inVector(minions, cardName)){
            addCard(std::shared_ptr<Basic_Minion>(new Basic_Minion{cardName, owner});
        }
        else if (inVector(spells, cardName)){
            addCard(std::shared_ptr<Spell>(new Spell{cardName, owner});
        }
        else if (inVector(enchantments, cardName)){
            addCard(std::shared_ptr<Enchantment>(new Enchantment{cardName, owner});
        }
        else if (inVector(rituals, cardName)){
            addCard(std::shared_ptr<Ritual>(new Ritual{cardName, owner});
        }
        else{
        }
        
    }
    
    if (shuffle){
        shuffle();
    }
}

void Deck::shuffle(){
    std::vector<std::shared_ptr<Card>> tempHolder;
    
    int originalLength = getCardCount();
    int length = originalLength;
    
    while (length > 0){
        int randIndex = rand() % length;
        
        tempHolder.emplace_back(getCard(randIndex));
        deleteCard(randIndex);
        
        length -= 1;
    }
    
    for (int i = 0; i < originalLength; ++i){
        addCard(tempHolder.at(i));
    }
   
   // swap temp vector with original cards
}
