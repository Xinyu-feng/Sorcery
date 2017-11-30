#ifndef _BOARD_SUBJECT_H_
#define _BOARD_SUBJECT_H_

#include "subject.h"
#include <memory>

class BoardSubject: public Subject{
    int myMinionCount;
    bool myRitual;
    int theirMinionCount;
    bool theirRitual;
    
    
    // Format of observers to follow the APNAP order:
    // [myMinion 1, ... myMinion 5, myRitual, theirMinion1, ..., theirMinion5, theirRitual]
    // Observers are only in above list if they are currently on the board
    
    
public:
    BoardSubject();
    
    void attachMinion(std::shared_ptr<Minion> m, bool owner);
    void detachMinion(std::shared_ptr<Minion> m, bool owner);
    void setRitual(std::shared_ptr<Ritual> r, bool owner);
    void desetRitual(std::shared_ptr<Ritual> r, bool owner);

}