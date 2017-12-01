#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <memory>
#include <utility>

#include "card.h"
#include "enchantment.h"
#include "basicminion.h"
#include "ritual.h"
#include "spell.h"

class Player;

std::shared_ptr<Card> createCard(std::string name, std::shared_ptr<Player> owner);

#endif
