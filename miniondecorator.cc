#include "miniondecorator.h"

#include <utility>

MinionDecorator::MinionDecorator(std::shared_ptr<Minion> m):m{m}{}

std::shared_ptr<Minion> getMinion(){
    return m;
}

