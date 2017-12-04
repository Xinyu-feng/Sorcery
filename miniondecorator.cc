#include "miniondecorator.h"

#include <memory>
#include "minion.h"

MinionDecorator::MinionDecorator(std::shared_ptr<Minion> m) {
	this->m = m;
}

std::shared_ptr<Minion> MinionDecorator::getMinion(){
    return m;
}

