#include "board.h"

using namespace std;

Board::Board():CardCollection{}, BoardSubject{}, minionCount{0}{

}

shared_ptr<Ritual> &Board::getRitual() { return ritual; }

void Board::play(shared_ptr<Minion> m){
    addCard(m);
    minionCount += 1;
    notify();
    attachMinion(m, true);
    
}

void Board::play(shared_ptr<Enchantment> e, int target){
    *getCard(target) = Enchant(b, std::shared_ptr<Enchantment>{this});
}

void Board::play(shared_ptr<Ritual> r){
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