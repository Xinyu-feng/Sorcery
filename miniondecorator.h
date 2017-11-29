#ifndef _MINION_DECORATOR_H_
#define _MINION_DECORATOR_H_

#include "minion.h"
#include <utility>

class MinionDecorator: public Minion{

    protected std::shared_ptr<Minion> m;

public:
    MinionDecorator(std::shared_ptr<Minion> m);
    
    virtual ~MinionDecorator();

};

#endif

