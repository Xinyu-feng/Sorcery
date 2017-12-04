#ifndef _CREATURE_DECORATOR_H_
#define _CREATURE_DECORATOR_H_

#include "creature.h"
#include <memory>

class CreatureDecorator: public Creature {

    protected:
        std::shared_ptr<Creature> c;

    public:
        CreatureDecorator(std::shared_ptr<Creature> c);
    
        std::shared_ptr<Creatue> getCreature();
    
        virtual ~CreatureDecorator() = 0; // do not remove original creature

};

#endif

