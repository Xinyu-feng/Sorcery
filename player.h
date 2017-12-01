#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <memory>
#include <string>

class Graveyard;
class Deck;
class Hand;
class Board;

class Player {
	Graveyard graveyard;
	Hand hand;
	Board myBoard;
	Board *otherBoard;
	Deck deck;
	int life;
	int magic;
	string name;
	
public:
    
    Player(std::string name, std::string deckFile, bool shuffle = true, int life = 20, int magic = 3);

	void draw();
	void play(int i, int p = 1, char t = '\0');
	void attack(int i, int j = 0);
	void use(int i, int p, int t);
	//void displayBoard();
	void discard(int i);
	void displayHand();
	
	void addMagic(int i);
	void deductMagic(int i);
	int getMagic();
	
	void addLife(int i);
	void deductLife(int i);
	int getLife();
};

#endif
