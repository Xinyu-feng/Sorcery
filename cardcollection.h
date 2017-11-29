#include <memory>
#include <vector>

class Card;

class CardCollection {
	std::vector <std::shared_ptr<Card>> cardList;
public:
    // -1 indicates you want to move the top card
    
	void moveCard(CardCollection &collect, int cardPosition = -1, bool board = false);
	int getCardCount();
	virtual ~CardCollection() = 0;
}
