#include "buffEnchantment.h"

using namespace std;

BuffEnchantment::BuffEnchantment(string name, shared_ptr<Player> owner, int manaCost, string attBuff, string defBuff, string description = "") :
    Enchantment{name, owner, manaCost, description}, attBuff{attBuff}, defBuff{defBuff} {}