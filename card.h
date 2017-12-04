#ifndef _CARD_H_
#define _CARD_H_
#include "ascii_graphics.h"
#include "observer.h"
#include <string>
#include <memory>

class Board;
class Subject;
class Player;
class State;

class Card: public Observer{
    std::string name;
    int manaCost;
    std::string description;

    public:
        Card(std::string name, int manaCost, std::string description = "");

        virtual void notify(State s);
	
    	int getManaCost();
	    std::string getName();
        std::string getDescription();

    	virtual card_template_t displayCard() = 0;
    	virtual void playCard(Board &b, int target = -1) = 0;
    	virtual ~Card() = 0;
};
#endif

