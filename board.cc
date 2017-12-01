#include <board.h>

Board::Board():CardCollection{}, BoardSubject{}, minionCount{0}{
    // Create the Ritual slot
    addCard(nullptr);
}

void Board::playMinion(std::shared_ptr<Minion> m){
    addCard(m);
    minionCount += 1;
    notify();
    attachMinion(m, true);
    
}

void Board::playEnchant(std::shared_ptr<Enchantment> e, int target){
    *getCard(target) = Enchant(b, std::shared_ptr<Enchantment>{this});
}

void Board::playRitual(std::shared_ptr<Ritual> r){
    attachRitual(r, true);
    setCard(r, 0);
}