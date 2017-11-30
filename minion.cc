#include "minion.h"

#include <utility>
#include <string>
#include <player.h>

using namespace std;

Minion::Minion(string name, shared_ptr<Player> owner, int manaCost, int attack, int defence, string description = "") :
    Card{name, owner, manaCost, description}, attack{attack}, defence{defence} {}

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
 
void Minion::addStats(int att, int def){
    attack += att;
    defence += def;
    
    if (attack < 0) attack = 0;
    if (defence < 0) defence = 0;
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

int getActivateCost(){
    return activateCost;
}
