#ifndef _CARD_H_
#define _CARD_H_
#include "observer.h"
#include <string>


class Card: public Observer{
	std::string name;
	int manaCost;
	std::string description;
	std::unique_ptr<Player> owner;
	
public:
    Card(std::string name, std::unique_ptr<Player> owner);

	void notify(Subject &whoFrom);
	
	int getManaCost();

	virtual void runEffect(Subject s);
	virtual void displayCard() = 0;
}
#endif

