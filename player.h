#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <memory>
#include <string>

class Graveyard;
class Deck;
class Hand;
class Board;

class Player {
	std::unique_ptr<Graveyard> graveyard;
	std::unique_ptr<Hand> hand;
	std::unique_ptr<Board> board;
	int life;
	int magic;
	string name;
	std::shared_ptr<Player> otherPlayer;
	public:
	Card draw();
	void play(int i, int p, char t);
	void attack(int i, int j = 0);
	void use(int i, int p, int t);
	//void displayBoard();
	void discard(int i);
	void displayHand();
	void addMagic(int i);
}

#endif
