#ifndef _BOARD_H_
#define _BOARD_H_

#include "ascii_graphics.h"
#include "boardsubject.h"
#include "cardcollection.h"
#include "state.h"
#include <string>
#include <vector>

class Enchantment;
class Minion;
class Ritual;
class Spell;
class State;

class Board: public CardCollection<Minion>, public BoardSubject {

	std::shared_ptr<Ritual> ritual;
	
public:
	Board();
	
	int getMinionCount();
	void play(std::shared_ptr<Spell> s, int target = -1);
	void play(std::shared_ptr<Minion> m);
	void play(std::shared_ptr<Enchantment> e, int target);
	void play(std::shared_ptr<Ritual> r);
	void use(int i, int t);
	
	card_template_t inspect(int i);
	//std::vector<string> displayBoard();
	//void attack(int i, int j);
	//void inflictDamage(int i, int d);
	std::shared_ptr<Ritual> getRitual();
	std::shared_ptr<Card> removeEnchant(int i);
	// -1 indicates you want the ritual
	void moveCardTo(int cardPosition, Hand &h) override;
	void moveCardTo(int cardPosition, Graveyard &g) override;
	void notifyObservers(State s);
};



#endif
