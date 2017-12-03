#include "hand.h"
#include "graveyard.h"

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
			(handDisplay.at(j))->append(currentCard.at(j));
		}
	}
	return handDisplay;
}

void Hand::moveCardTo(int cardPosition, Graveyard &g) {
    cardList.at(cardPosition)->destroy(g);
    cardList.erase(cardList.begin() + i);
}