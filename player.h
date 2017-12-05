#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <memory>
#include <string>
#include "board.h"
#include "deck.h"
#include "graveyard.h"
#include "hand.h"

class State;
class Card;
class Ritual;
class TriggerMinion;

class Player {
	int player;
	Graveyard graveyard;
	Hand hand;
	Board myBoard;
	Player *otherPlayer;
	Board *otherBoard;
	std::string name;
	Deck deck;
	int life = 20;
	int magic = 3;
	
	public:
	Player(int player, std::string name, std::string deckFile, bool shuffle);
	
	void setOtherPlayer(Player *otherPlayer);
	void setOtherBoard(Board *otherBoard);
	Board *getBoard();

	void draw(int i = 1);
	void play(int i, int p = 0, char t = '\0');
	void playTargetCard(std::shared_ptr<Card> c, char t);
	void attack(int i, int j = 0);
	void use(int i, int p, int t);
	std::vector<std::string> displayBoard();
	std::vector<std::string> displayBoardMinions();
	std::vector<std::string> displayBoardRest();
	void discard(int i);
	std::vector<std::string> displayHand();
	std::vector<std::string> inspectMinion(int i);
	
	void destroyMinion(int i);
	void returnToHand(int i);
	
	void deductMagic(int i, bool testing);
	int getMagic();
	
	void deductLife(int i);
	int getPlayerNumber();
	int getLife();
	void notifyApnap(State s);
	void runRitual(Ritual &r, State s);
	void runTriggerMinion(TriggerMinion &tm, State s);
};

#endif
