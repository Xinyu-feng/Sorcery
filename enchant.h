#ifndef _ENCHANT_H_
#define _ENCHANT_H_


#include "miniondecorator.h"

class Enchant: public MinionDecorator{

    Enchant(std::shared_ptr<Minion> m, std::shared_ptr<Enchantment> e);
    
    void runEffect(Subject &board);


#endif