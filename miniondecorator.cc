#include "miniondecorator.h"

#include <memory>
#include "abstactminion.h"

using namespace std;

MinionDecorator::MinionDecorator(shared_ptr<AbstractMinion> m) : m{m} {}

std::shared_ptr<AbstractMinion> MinionDecorator::getAbstractMinion(){
    return m;
}

MinionDecorator::~MinionDecorator() {} // do not remove original minion; retain it somehow