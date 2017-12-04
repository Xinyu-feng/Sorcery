#ifndef CREATURE_H
#define CREATURE_H

class Creature {}
    public:
        virtual int getAttack() = 0;
        virtual int getDefence() = 0;
        virtual int getActions() = 0;
        virtual int getAbilityCost() = 0;
        virtual bool active = 0;
}

#endif