#ifndef STATE_H
#define STATE_H

class Player;

enum class Trigger { Begin, Summon, Leave, End };

struct State {
    Player &player; // player who triggered the notify
    Trigger trigger;
    int index = -1; // index of card on board, if trigger is summon/activate/leave
};

#endif
