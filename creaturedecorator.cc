#include "creaturedecorator.h"

#include <memory>
#include "creature.h"

CreatureDecorator::CreatureDecorator(Creature *c) : c{c} {}

std::shared_ptr<Creature> CreatureDecorator::getCreature(){
    return c;
}

CreatureDecorator::~CreatureDecorator() {} // do not remove original minion; retain it somehow