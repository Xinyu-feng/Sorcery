#ifndef _CARD_H_
#define _CARD_H_
#include "ascii_graphics.h"
#include "observer.h"
#include <string>
#include <memory>

class Board;
class Subject;
class Player;

class Card: public Observer{
	std::string name;
	int manaCost;
	std::string description;
	std::shared_ptr<Player> owner;
	
	public:
	Card(std::string name, std::shared_ptr<Player> owner, int manaCost, std::string description = "");

	void notify(Subject &whoFrom);
	
	int getManaCost();
	
	std::string getName();

	std::string getDescription();

	virtual void runEffect(Subject &board);
	virtual card_template_t displayCard() = 0;
	
	virtual void playCard(Board &b, int target = -1) = 0;
	
	virtual ~Card() = 0;
};
#endif

