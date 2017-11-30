#ifndef _BOARD_H_
#define _BOARD_H_



#include "cardcollection.h"
#include "state.h"

class Board: public CardCollection{

    int minionCount;
    State s;
    
public:
    Board();
    
    int getMinionCount();
    
    void playMinion(std::shared_ptr<Minion> m);
    void playEnchant(std::shared_ptr<Enchantment> e, int target);
    void playRitual(std::shared_ptr<Ritual> r);
    
    




};



#endif