#ifndef _BASICMINION_H_
#define _BASICMINION_H_

#include "card.h"

class BasicMinion: public Minion{
    
public:
    BasicMinion(std::string name, std::shared_ptr<Player> owner);
    
    void runEffect(Subject &board);
    
}


#endif
