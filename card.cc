#include "card.h"
#include "subject.h"
#include "state.h"

Card::Card(std::string name, std::shared_ptr<Player> owner):name{name}, owner{owner}{
    
}

void Card::notify(Subject &whoFrom){
	runEffect(whoFrom);
}

void Card::getManaCost(){
    return manaCost;
}
