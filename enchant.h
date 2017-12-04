#ifndef _ENCHANT_H_
#define _ENCHANT_H_


#include "miniondecorator.h"
#include "enchantment.h"
#include <memory>

class Enchant: public MinionDecorator{
    
    std::shared_ptr<Enchantment> e;
    public:
        Enchant(std::shared_ptr<AbstractMinion> m, std::shared_ptr<Enchantment> e);
    
        std::shared_ptr<AbstractMinion> removeEnchant();
        int getAttack() override;
        int getDefence() override;
        int getActions() override;
        int getAbilityCost() override;
        bool active override;
        std::vector<card_template_t> inspectMinion() override;

        card_template_t displayCard() override;
    
};


#endif
