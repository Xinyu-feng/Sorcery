#include "enchantment.h"
#include <utility>
#include "state.h"

using namespace std;

Enchantment::Enchantment(string name, shared_ptr<Player> owner, int manaCost, string description = "") : 
    Card{name, owner, manaCost, description} {}

void Enchantment::runEffect(State s){...} // move to helper function