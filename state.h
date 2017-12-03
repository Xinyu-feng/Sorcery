#ifndef STATE_H
#define STATE_H

#include "card.h"
#include <utility>

enum class Trigger { Begin, Summon, Activate, Leave, End };

struct State {
  std::shared_ptr<Card> card;
  Trigger trigger;
  std::shared_ptr<Player> owner;
  int position;
  bool ritual;
};

#endif
