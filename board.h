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
    
    void playCard(
    
    




};



#endif