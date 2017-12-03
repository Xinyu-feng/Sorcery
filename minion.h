#ifndef _MINION_H_
#define _MINION_H_
#include "card.h"

class State;

class Minion: public Card {
	int attack;
	int defense;
	int maxActions = 1;
	int currActions = 0;

	public:
	Minion(std::string name, int manaCost, int attack, int defence, std::string description = "");
	void addAction(int i);
	void lowerAction(int i);
	void setAction(int i);
	int getAction();

	void addStats(int attack, int defence);
	void setAttack(int i);
	void setDefense(int i);

	void setStats(int attack, int defence);

	int getAttack();
	int getDefense();
	
	virtual card_template_t displayCard() override;

	void playCard(Board &b, int target = -1) override;

	//virtual void runEffect(State s) = 0;

	virtual ~Minion() = 0;
};

#endif
