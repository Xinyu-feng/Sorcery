#ifndef _MINION_H_
#define _MINION_H_
#include "card.h"

class State;

class Minion: public Card, public Creature {
	int attack;
	int defense;
	int maxActions = 1;
	int currActions = 0;

	public:
	Minion();
	Minion(std::string name, int manaCost, int attack, int defense, std::string description = "");

	void attackOther(Player * other);
	void attackOther(std::shared_ptr<Minion> other);	
	
	// these deal with maxActions
	void addAction(int i);
	void lowerAction(int i);
	void setAction(int i);
	int getActions();

	void addStats(int attack, int defense);
	void setAttack(int i);
	void setDefense(int i);

	void setStats(int attack, int defense);

	int getAttack();
	int getDefense();
	
	virtual card_template_t displayCard() override;
	
	virtual std::vector<card_template_t> inspectMinion() = 0;

	void playCard(Board &b, int target = -1) override;
	
	bool isMinion() override;

	//virtual void runEffect(State s) = 0;

	virtual ~Minion() = 0;
};

#endif
