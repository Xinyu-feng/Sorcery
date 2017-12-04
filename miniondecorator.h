#ifndef _MINION_DECORATOR_H_
#define _MINION_DECORATOR_H_

#include "minion.h"
#include <memory>

class MinionDecorator: public Minion{

    Minion *m;

public:
    MinionDecorator(Minion *m);
    
    std::shared_ptr<Minion> getMinion();
    
    virtual ~MinionDecorator() = default; // do not remove original minion

};

#endif

