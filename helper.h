#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <utility>
#include card.h
#include player.h

Card createCard(std::string name, std::shared_ptr<Player> owner);

#endif