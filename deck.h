#include "cardcollection.h"

class Deck: public CardCollection {
	public:
	void shuffle();
	Card draw();
}
