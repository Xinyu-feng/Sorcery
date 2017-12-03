#ifndef _MINION_DECORATOR_H_
#define _MINION_DECORATOR_H_

#include "minion.h"
#include <utility>

class MinionDecorator: public Minion{

    std::shared_ptr<Minion> m;

public:
    MinionDecorator(std::shared_ptr<Minion> m);
    
    std::shared_ptr<Minion> getMinion();
    
    virtual ~MinionDecorator();

};

#endif

