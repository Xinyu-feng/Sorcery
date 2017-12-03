#include <board.h>

Board::Board():CardCollection{}, BoardSubject{}, minionCount{0}{

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
    ritual = r;
}

void Board::moveCardTo(int cardPosition, Hand &h) {
    if (h.getCardCount() == 5) { // full hand
        // throw ...
    }
    if (cardPosition == -1) {
        h.addCard(ritual);
        ritual.reset();
    } else {
        h.addCard(cardList.at(cardPosition));
        cardList.erase(cardPosition);
    }
}

void Board::moveCardTo(int cardPosition, Graveyard &g) {
    g.addCard(cardList.at(cardPosition));
    cardList.erase(cardPosition);
}