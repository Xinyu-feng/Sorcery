#include "miniondecorator.h"

#include <memory>
#include "minion.h"

MinionDecorator::MinionDecorator(Minion *m) : m{m} {}

std::shared_ptr<Minion> MinionDecorator::getMinion(){
    return m;
}

MinionDecorator::~MinionDecorator() {} // do not remove original minion; retain it somehow