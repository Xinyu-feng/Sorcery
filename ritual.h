#ifndef _RITUAL_H_
#define _RITUAL_H_

#include "card.h"
#include "observer.h"

class State;

class Ritual: public Card, public Observer {
    int charges;
    int activationCost;
    bool active = true;

    public:
    Ritual(std::string name, int manaCost, int charges, int activationCost, std::string description = "");
    
    void notify(State s) override;
    
    void playCard(Board &b, int target) override;

    card_template_t displayCard() override;
    void addCharges(int i);
    void addActivateCost(int i);
    void activate();
};

#endif
