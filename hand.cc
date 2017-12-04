#include <memory>

#include "board.h"
#include "hand.h"
#include "graveyard.h"
#include "minion.h"

using namespace std;

card_template_t Hand::displayHand() {
	int cardHeight = 11;
	card_template_t handDisplay(cardHeight, "");
	int cardCount = this->getCardCount();
	for (int i = 0; i < cardCount; ++i) {
		// get display for current hand
		card_template_t currentCard = (this->getCard(i))->displayCard();
		// add each line of display to each line of handDisplay
		for (int j = 0; j < cardHeight; ++j) {
			(handDisplay.at(j)).append(currentCard.at(j));
		}
	}
	return handDisplay;
}

void Hand::moveCardTo(int cardPosition, Graveyard &g) {
    g.addCard(dynamic_pointer_cast<Minion>(cardList.at(cardPosition)));
    cardList.erase(cardList.begin() + cardPosition);
}

void Hand::moveCardTo(int cardPosition, Board &b, int target) {
	// should call different play fn depending on type
    //b.play(cardList.at(cardPosition));
    //cardList.erase(cardList.begin() + cardPosition);
}
