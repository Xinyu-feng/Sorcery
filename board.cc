#include <board.h>

Board::Board():CardCollection{}, BoardSubject{}, minionCount{0}{
    addCard(nullptr);
}

void Board::playMinion(std::shared_ptr<Minion> m){
    attachMinion(m, true);
    addCard(m);
    minionCount += 1;
}

void Board::playEnchant(std::shared_ptr<Enchantment> e, int target){
    
}

void Board::playRitual(std::shared_ptr<Ritual> r, int target){
    attachRitual(r, true);
    
}