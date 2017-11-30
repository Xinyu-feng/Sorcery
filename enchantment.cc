#include "enchantment.h"
#include <utility>
#include "state.h"

using namespace std;

Enchantment::Enchantment(string name, shared_ptr<Player> owner, int manaCost, string description = "", string attBuff = "", string defBuff = "") : 
    Card{name, owner, manaCost, description}, attBuff{attBuff}, defBuff{defBuff} {}

void Enchantment::runEffect(State s){...} // move to helper function