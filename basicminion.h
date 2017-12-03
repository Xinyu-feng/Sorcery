#ifndef _BASICMINION_H_
#define _BASICMINION_H_

#include "minion.h"

class BasicMinion: public Minion {

public:
    BasicMinion(std::string name, int manaCost, int attack, int defence, std::string description = "");
    
    void runEffect(Subject &board) override;
    
};


#endif
