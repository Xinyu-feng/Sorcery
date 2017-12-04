#ifndef STATE_H
#define STATE_H

enum class Trigger { Begin, Summon, Activate, Leave, End };

class Player;

struct State {
    Player &player; // player who triggered the notify
    Trigger trigger;
    int index = -1; // index of card on board, if trigger is summon/activate/leave
};

#endif
