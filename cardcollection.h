#include <memory>
#include <vector>

class Card;

class CardCollection {
	std::vector <std::shared_ptr<Card>> cardList;
public:
	void moveCard(int i, CardCollection &collect);
	int getCardCount();
	virtual ~CardCollection() = 0;
}
