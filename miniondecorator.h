#ifndef _MINION_DECORATOR_H_
#define _MINION_DECORATOR_H_

#include "abstractminion.h"
#include <memory>

class MinionDecorator: public AbstractMinion {

    protected:
        std::shared_ptr<AbstractMinion> m;

    public:
        MinionDecorator(std::shared_ptr<AbstractMinion> m);
    
        std::shared_ptr<AbstractMinion> getAbstractMinion();
    
        virtual ~MinionDecorator() = 0; // do not remove original AbstractMinion

};

#endif

