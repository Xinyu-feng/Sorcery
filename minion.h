#ifndef _MINION_H_
#define _MINION_H_

#include "card.h"

class Minion: public Card{
    
    int attack;
    int defense;
    int actions = 0;
    int activateCost = 0;
    
public:

    Minion(std::string name, std::shared_ptr<Player> owner);

    void addAction(int i);
    void lowerAction(int i);
    void setAction(int i);
    int getAction();
    
    void addAttack(int i);
    void addDefense(int i);
    
    void addStats(int attack, int defence);
    
    void setAttack(int i);
    void setDefense(int i);
    
    void setStats(int attack, int defence);
    
    void lowerAttack(int i);
    void lowerDefense(int i);
    
    void lowerStats(int attack, int defense);
    
    int getAttack();
    int getDefense();
    
    void addActivateCost(int i);
    void setActivateCost(int i);
    void lowerActivateCost(int i);
    int getActivateCost();
    
    
    virtual void runEffect(State s)=0;
    
    virtual void ~Minion() = 0;
};

#endif
