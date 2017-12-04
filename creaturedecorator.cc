#include "creaturedecorator.h"

#include <memory>
#include "creature.h"

using namespace std;

CreatureDecorator::CreatureDecorator(shared_ptr<Creature> c) : c{c} {}

std::shared_ptr<Creature> CreatureDecorator::getCreature(){
    return c;
}

CreatureDecorator::~CreatureDecorator() {} // do not remove original minion; retain it somehow