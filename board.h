#ifndef _BOARD_H_
#define _BOARD_H_

#include "cardcollection.h"
#include "state.h"
#include <string>
#include <vector>

class Trigger;
class Minion;
class Ritual;

class Board: public CardCollection<Minion> {

	int minionCount;
	State s;
	void setState(Card c, Trigger trigger);
	State getState();
	
	std::shared_ptr<Ritual> ritual;
	
public:
	Board();
	Card returnToHand(int i);
	
	int getMinionCount();
	
	
	void playMinion(std::shared_ptr<Minion> m);
	void playEnchant(std::shared_ptr<Enchantment> e, int target);
	void playRitual(std::shared_ptr<Ritual> r);
    

    void use(int i, int t);
    std::vector<string> inspect(int i);
    //std::vector<string> displayBoard();
    void attack(int i, int j);
    void inflictDamage(int i, int d);
    int getMinionCount();
    Card removeEnchant(int i);


};



#endif
