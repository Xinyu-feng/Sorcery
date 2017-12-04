#ifndef ABSTRACTMINION_H
#define ABSTRACTMINION_H

class AbstractMinion {
    public:
        virtual int getAttack() = 0;
        virtual int getDefense() = 0;
        virtual int getActions() = 0;
        virtual int getAbilityCost() = 0;
        virtual bool active() = 0;
};

#endif
