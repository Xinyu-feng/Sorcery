#include "card.h"

#include "subject.h"
#include "state.h"
#include <utility>

using namespace std;

Card::Card(string name, shared_ptr<Player> owner, int manaCost, string description = "") : 
    name{name}, owner{owner}, manaCost{manaCost}, description{description} {}

string Card::getName() {
    return name;
}

void Card::notify(Subject &whoFrom) {
	runEffect(whoFrom);
}

void Card::getManaCost(){
    return manaCost;
}
