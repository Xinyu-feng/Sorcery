#include "graveyard.h"
#include "hand.h"
#include "board.h"
#include "card.h"
#include "minion.h"
#include <memory>

using namespace std;

void Graveyard::moveCardTo(int cardPosition, Hand &h) {
	if (h.getCardCount() == 5) {
	}
	if (cardPosition == -1) {
	}
	else {
		h.addCard(cardList.at(cardPosition));
		cardList.erase(cardList.begin() + cardPosition);
	}
}

void Graveyard::moveCardTo(int cardPosition, Board &b, int target, int defense) {
    cardList.at(cardPosition)->setDefense(defense);
	b.play(cardList.at(cardPosition));
	cardList.erase(cardList.begin() + cardPosition);
}
