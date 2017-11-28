#ifndef _BASICMINION_H_
#define _BASICMINION_H_

#include "card.h"

class BasicMinion: public Minion{
    
public:
    BasicMinion(std::string name, std::shared_ptr<Player> owner):Minion{name, owner}{
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
    
}


#endif
