#ifndef STATE_H
#define STATE_H

enum class Trigger { Begin, Summon, Activate, Leave, End };

struct State {
  Trigger trigger;
  int index = -1; // index of card on board, if trigger is summon/activate/leave
};

#endif
