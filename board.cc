#include "board.h"
#include "minion.h"
#include "card.h"
#include "hand.h"
#include "ritual.h"
#include "spell.h"
#include "graveyard.h"
#include "state.h"
#include <string>

using namespace std;

Board::Board() : CardCollection<Minion>{} {

}

shared_ptr<Ritual> Board::getRitual() { return ritual; }

void Board::play(shared_ptr<Minion> m){
	addCard(m);
}

void Board::play(shared_ptr<Spell> s, int target){
    if (s->getName() == "Recharge") {
        if (ritual) {
            ritual->addCharges(3);
        } else {
            // throw ...
        }
    } else if (s->getName() == "Blizzard") {
        for (auto minion : cardList) {
            dynamic_pointer_cast<Minion>(minion)->addStats(0, -2);
        }
    }
}

void Board::play(shared_ptr<Enchantment> e, int target) {
    //*getCard(target) = Enchant(e, std::shared_ptr<Enchantment>{this});
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
        cardList.erase(cardList.begin() + cardPosition);
    }
}

void Board::moveCardTo(int cardPosition, Graveyard &g) {
    g.addCard(cardList.at(cardPosition));
    cardList.erase(cardList.begin() + cardPosition);
}


card_template_t Board::inspect(int i){
    std::vector<card_template_t> cards = getCard(i-1)->inspectMinion();
    
    int cardCount = cards.size();
    
    card_template_t inspectDisplay = cards.at(0);
    
    int topCardHeight = 0;
    
    for (int i = 1; i < cardCount; ++i){
        // If you need a new row (i.e. cards #1, 6, 11, etc)
        if (i % 5 == 1){
            topCardHeight += 11;
            // Adding new lines
            for (int j = 0; j < 11; ++j){
                inspectDisplay.emplace_back(std::string{""});
            }
        }
        
        // Adding the card to the display
        for (int l = 0; l < 11; ++l){
            inspectDisplay.at(topCardHeight + l).append(cards.at(i).at(l));
        }
    }
    
    return inspectDisplay;
}

void Board::notifyObservers(State s) {
    for (auto minion : cardList) {
        minion->notify(s);
    }
    ritual->notify(s);
}

