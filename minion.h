#ifndef _MINION_H_
#define _MINION_H_

#include "card.h"

class Minion: public Card{
    
    int attack;
    int defense;
    int actions = 0;
    
public:
    int addAction(int i);
    int addAttack(int i);
    int addDefense(int i);
    
    int setAttack(int i);
    int setDefense(int i);
    
    virtual void runEffect(State s)=0;
}