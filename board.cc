#include "board.h"

Board::Board():CardCollection{}, minionCount{0}{
    addCard(nullptr);
}
