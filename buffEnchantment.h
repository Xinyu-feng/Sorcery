#ifndef BUFFENCHANTMENT_H
#define BUFFENCHANTMENT_H

class BuffEnchantment : public Enchantment {
    public:
        BuffEnchantment(std::string name, std::shared_ptr<Player> owner, int manaCost, std::string attBuff, std::string defBuff, std:string description = "");
};