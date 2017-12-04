#ifndef _EFFECT_H_
#define _EFFECT_H_

#include <string>
#include "state.h"


class Effect{

    std::string effectType;
    
    
public:
    
    void runEffect(Subject &board);
    
};

#endif