#include "minion.h"

#include <utility>
#include <string>
#include <player.h>

Minion::Minion(std::string name, std::shared_ptr<Player> owner):Card{name, owner}{
    
}

void Minion::addAction(int i){
    actions += 1;
}

void Minion::lowerAction(int i){
    actions -= i;
    if (actions <= 0){
        actions = 0;
    }
}

void Minion::setAction(int i ){
    actions = i;
    if (actions < 0){
        actions = 0;
    }
}

int Minion::getAction(){
    return actions;
}
    
void Minion::addAttack(int i){
    attack += i;
}

void Minion::addDefense(int i){
    defense += i;
}
 
void Minion::addStats(int attack, int defense){
    addAttack(attack);
    addDefense(defense);
}

void Minion::setAttack(int i){
    attack = i;
    if (attack < 0){
        attack = 0;
    }
}

void Minion::setDefense(int i){
    defense = i;
    if (defense < 0){
        defense = 0;
    }
}
    
void Minion::setStats(int attack, int defense){
    setAttack(attack);
    setDefense(defense);
}
    
void Minion::lowerAttack(int i){
    attack -= i;
    if (attack < 0){
        attack = 0;
    }
}

void Minion::lowerDefense(int i){
    defense -= i;
    if (defense < 0){
        defense = 0;
    }
}
    
void lowerStats(int attack, int defense){
    lowerAttack(attack);
    lowerDefense(defense);
}

int Minion::getAttack(){ return attack;}
int Minion::getDefense(){ return defense;}