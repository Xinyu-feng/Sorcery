#include <memory>
#include <vector>

class Card;

class CardCollection {
	std::vector <std::shared_ptr<Card>> cardList;
public:

    // This function moves a card to the collect CardCollection
    // cardPosition represents the position of the card in the deck
    // The board flag indicates that you are moving the card to the board which requires special behaviour
    // In the case that the board is the destination, you need to track the target for spells and enhancements
	void moveCard(CardCollection &collect, int cardPosition = -1, bool board = false, int target = -1);
	int getCardCount();
	virtual ~CardCollection() = 0;
}
