#ifndef _TRIGGERMINION_H_
#define _TRIGGERMINION_H_

#include "minion.h"
#include "observer.h"

class TriggerMinion: public Minion, public Observer {

public:
    TriggerMinion(std::string name, int manaCost, int attack, int defence, std::string description = "");

    card_template_t displayCard() override;
    std::vector<card_template_t> inspectMinion() override;    
    void notify(State s) override;
};

#endif