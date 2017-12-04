#ifndef _MINION_H_
#define _MINION_H_
#include "card.h"

class State;

class Minion: public Card, public AbstractMinion {
	int attack;
	int defense;
	int maxActions = 1;
	int currActions = 0;

	public:
	Minion(std::string name, int manaCost, int attack, int defense, std::string description = "");

	void attackOther(Player * other);
	void attackOther(std::shared_ptr<Minion> other);	
	
	void lowerAction(int i);
	void setAction(int i);
	int getActions() override;

	void addStats(int attack, int defense);
	void setAttack(int i);
	void setDefense(int i);

	void setStats(int attack, int defense);

	int getAttack() override;
	int getDefense() override;
	virtual int getAbilityCost() override;
	virtual bool active override;
	
	virtual card_template_t displayCard() override;
	virtual std::vector<card_template_t> inspectMinion() = 0;

	void playCard(Board &b, int target = -1) override;
	
	bool isMinion() override;

	//virtual void runEffect(State s) = 0;

	virtual ~Minion() = 0;
};

#endif
