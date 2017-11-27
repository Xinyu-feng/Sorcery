#ifndef STATE_H
#define STATE_H

#include "card.h"
#include <utility>

enum class Trigger { Begin, Summon, End };

struct State {
  std::shared_ptr<Card> card;
  Trigger trigger;
};

#endif
