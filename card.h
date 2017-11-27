#ifndef _CARD_H_
#define _CARD_H_
#include "observer.h"
#include <string>


class Card: public Observer{
	std::string name;
	int manaCost;
	std::string description;

	void notify(Subject &whoFrom);

	virtual void runEffect(Card c, Trigger t);
	virtual void displayCard() = 0;


}
#endif

