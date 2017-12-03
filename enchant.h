#ifndef _ENCHANT_H_
#define _ENCHANT_H_


#include "miniondecorator.h"
#include "enchantment.h"
#include <memory>

class Enchant: public MinionDecorator{
    
    std::shared_ptr<Enchantment> e;

    Enchant(std::shared_ptr<Minion> m, std::shared_ptr<Enchantment> e);
    
    void runEffect(Subject &board) override;
    
    std::shared_ptr<Minion> removeEnchant();
    
    std::vector<card_template_t> inspectMinion() override;

    card_template_t displayCard() override;
    
};


#endif
