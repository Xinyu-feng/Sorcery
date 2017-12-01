#ifndef _ENCHANT_H_
#define _ENCHANT_H_


#include "miniondecorator.h"
#include "enchantment.h"
#include <utility>

class Enchant: public MinionDecorator{
    
    std::shared_ptr<Enchantment> e;

    Enchant(std::shared_ptr<Minion> m, std::shared_ptr<Enchantment> e);
    
    void runEffect(Subject &board);
    
    std::shared_ptr<Minion> removeEnchant();
    
};


#endif