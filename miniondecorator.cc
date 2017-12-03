#include "miniondecorator.h"

#include <memory>
#include "minion.h"

MinionDecorator::MinionDecorator(std::shared_ptr<Minion> m):m{m}{}

std::shared_ptr<Minion> getMinion(){
    return m;
}

