#include "boardsubject.h"

BoardSubject::BoardSubject(): myMinionCount{0}, myRitual{false}, theirMinionCount{0}, theirRitual{false}{}

// This method attaches minions to the observer list in APNAP order
void BoardSubject::attachMinion(std::shared_ptr<Minion> m, bool owner){
    int insertIndex = myMinionCount;
    if (owner){
        ++myMinionCount;
    }
    else{
        if (myRitual) insertIndex += 1;
        insertIndex += theirMinionCount;
        ++theirMinionCount;
    }
    attach(m, insertIndex);
}

// This method detaches the minion
void BoardSubject::detachMinion(std::shared_ptr<Minion> m, bool owner){
    detach(m);
    if (owner) --myMinionCount;
    else --theirMinionCount;
}

// This method attaches the ritual to the observer list in APNAP order
void BoardSubject::setRitual(std::shared_ptr<Ritual> r, bool owner){
    int index = myMinionCount;
    if (owner){
        if (myRitual){
            replace(r, index);
        }
        else{
            myRitual = true;
            attach(r, index);
        }
    }
    else{
        if (myRitual) index += 1;
        index += theirMinionCount;
        if (theirRitual){
            replace(r, index);
        }
        else{
            theirRitual = true;
            attach(r, index);
        }
    }
}

// This method detaches the ritual
void BoardSubject::desetRitual(std::shared_ptr<Ritual> r, bool owner){
    detach(r);
    if (owner) myRitual = false;
    else theirRitual = false;
}