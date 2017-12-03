#include "board.h"

using namespace std;

Board::Board():CardCollection{}, BoardSubject{}, minionCount{0}{

}

shared_ptr<Ritual> &Board::getRitual() { return ritual; }

void Board::play(shared_ptr<Minion> m){
    addCard(m);
    minionCount += 1;
    // notifyObservers(m, state);
}

void Board::play(shared_ptr<Spell> s){
    if (s->getName() == "Recharge") {
        if (ritual) {
            ritual.addCharges(3);
        } else {
            // throw ...
        }
    } else if (s->getName == "Blizzard") {
        for (auto minion : cardList) {
            minion->addStats(0, -2);
        }
    }
}

void Board::play(shared_ptr<Enchantment> e, int target) {
    *getCard(target) = Enchant(b, std::shared_ptr<Enchantment>{this});
}

void Board::play(shared_ptr<Ritual> r) {
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

void Board::notifyObservers() {
    for (auto minion : cardList) {
        minion->notify();
    }
}