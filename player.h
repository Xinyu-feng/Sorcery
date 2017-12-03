#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <memory>
#include <string>
#include "board.h"
#include "deck.h"
#include "graveyard.h"
#include "hand.h"

class Player {
	int player;
	Graveyard graveyard;
	Hand hand;
	Board myBoard;
	std::shared_ptr<Player> otherPlayer;
	Deck deck;
	int life = 20;
	int magic = 3;
	std::string name;
	
	public:
	Player(int player, std::string name, std::string deckFile);

	void draw(int i = 1);
	void play(int i, int p = 0, char t = '\0');
	void attack(int i, int j = 0);
	void use(int i, int p, int t);
	//std::vector<std::string> displayBoard();
	void discard(int i);
	//std::vector<std::string> displayHand();
	
	void deductMagic(int i);
	int getMagic();
	
	void deductLife(int i);
	int getLife();
};

#endif
