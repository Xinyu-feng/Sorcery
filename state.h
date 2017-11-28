#ifndef STATE_H
#define STATE_H

#include "card.h"
#include <utility>
#include "player.h"

enum class Trigger { Begin, Summon, Leave, End };

struct State {
  std::shared_ptr<Card> card;
  Trigger trigger;
  std::shared_ptr<Player> owner;
  int position;
  bool ritual;
};

#endif
