#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <memory>
#include <string>
#include "board.h"
#include "deck.h"
#include "graveyard.h"
#include "hand.h"

class State;

class Player {
	int player;
	Graveyard graveyard;
	Hand hand;
	Board myBoard;
	Player *otherPlayer;
	Board *otherBoard;
	Deck deck;
	int life = 20;
	int magic = 3;
	std::string name;
	
	public:
	Player(int player, std::string name, std::string deckFile, bool shuffle);
	
	void setOtherPlayer(Player *otherPlayer);
	void setOtherBoard(Board *otherBoard);
	Board *getBoard();

	void draw(int i = 1);
	void play(int i, int p = 0, char t = '\0');
	void attack(int i, int j = 0);
	void use(int i, int p, int t);
	//std::vector<std::string> displayBoard();
	void discard(int i);
	std::vector<std::string> displayHand();
	std::vector<std::string> inspectMinion(int i);
	
	void deductMagic(int i);
	int getMagic();
	
	void deductLife(int i);
	int getLife();
	void notifyApnap(State s);
	void runEffect(Card &c, State s);
};

#endif
