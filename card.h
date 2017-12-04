#ifndef _CARD_H_
#define _CARD_H_
#include "ascii_graphics.h"
#include <string>
#include <memory>

class Board;
class Player;
class State;

class Card {
    std::string name;
    int manaCost;
    std::string description;

    public:
        Card(std::string name, int manaCost, std::string description = "");

        virtual void notify(State s);
	
    	int getManaCost();
	    std::string getName();
        std::string getDescription();

        virtual bool isMinion(); // for observer pattern
    	virtual card_template_t displayCard() = 0;
    	virtual ~Card() = 0;
};
#endif

