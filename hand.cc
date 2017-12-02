#include "hand.h"

card_template_t Hand::displayHand() {
	int cardHeight = 11;
	card_template_t handDisplay(cardHeight, "");
	int cardCount = this->getCardCount();
	for (int i = 0; i < cardCount; ++i) {
		// get display for current hand
		card_template_t currentCard = (this->getCard(i))->displayCard();
		// add each line of display to each line of handDisplay
		for (int j = 0; j < cardHeight; ++j) {
			(handDisplay.at(j))->append(currentCard.at(j));
		}
	}
	return handDisplay;
}
