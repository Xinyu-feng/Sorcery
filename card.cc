#include "card.h"

#include "subject.h"
#include "state.h"
#include <utility>

using namespace std;

Card::Card(string name, int manaCost, string description) : 
    name{name}, manaCost{manaCost}, description{description} {}

string Card::getName() {
    return name;
}

string Card::getDescription() {
	return description;
}

int Card::getManaCost(){
    return manaCost;
}

bool Card::isMinion() { return false; }