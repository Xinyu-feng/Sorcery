#ifndef _BOARD_H_
#define _BOARD_H_

#include "cardcollection.h"
#include "state.h"
#include <string>
#include <vector>

class Trigger;

class Board: public CardCollection {

	int minionCount;
	State s;
	void setState(Card c, Trigger trigger);
	State getState();
	
	public:
	Board();
	Card returnToHand(int i);
	
	int getMinionCount();
	
	/*
	void playMinion(std::shared_ptr<Minion> m);
	void playEnchant(std::shared_ptr<Enchantment> e, int target);
	void playRitual(std::shared_ptr<Ritual> r);
    */
    void playCard(std::shared_ptr<Minion> card, int i);
    void playCard(std::shared_ptr<Enchantment> card, int target);
    void playCard(std::shared_ptr<Ritual> card, int i);
    void playCard(std::shared_ptr<Spell> card, int target);
    void use(int i, int t);
    std::vector<string> inspect(int i);
    //std::vector<string> displayBoard();
    void attack(int i, int j);
    void inflictDamage(int i, int d);
    int getMinionCount();
    Card removeEnchant(int i);


};



#endif
