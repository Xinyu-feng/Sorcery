#include "card.h"
#include "subject.h"
#include "state.h"

Card::Card(std::string name):name{name}{
    
}

void Card::notify(Subject &whoFrom){
	runEffect(whoFrom);
}

void Card::getManaCost(){
    return manaCost;
}
