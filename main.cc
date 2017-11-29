#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Player;

int main(int argc, char *argv[]) {

	Player player1;
	Player player2;
	istream &in = cin;
	ifstream initFile;

	ifstream player1Deck{"default.deck"};
	ifstream player2Deck{"default.deck"};
	
	bool testing = false;

	if (argv.size() > 1) {
		for (int i = 1; i < argv.size(); ++i) {
			if (argv[i] == "-deck1" && i != argv.size() - 1) {
				// close currently open deck file
				player1Deck.close();
				// load deck from file
				player1Deck.open(argv[i + 1]);
			}
			else if (argv[i] == "-deck2" && i != argv.size() - 1) {
				// close currently open deck file
				player2Deck.close();
				// load deck from file
				player2Deck.open(argv[i + 1]);
			}
			else if (argv[i] == "-init" && i != argv.size() - 1) {
				// try to open following argv element
				// set &in to the file stream to be opened
				initFile.open(argv[i + 1]);
				in = initFile;
			}
			else if (argv[i] == "-testing") {
				testing = true;
			}
			else if (argv[i] == "-graphics") {
				// enable graphical interface
			}
		}
	}
	
	// load player decks from file stream
	string input;
	int turnPlayer = 1;

	// main game loop
	while (true) {
		// default to cin after end of -init file
		if (in.eof()) {
			in = cin;
		}
		// each input on its own line
		getline(in, input);
		istringstream iss{input};
		if (iss >> input) {
			if (input == "help") {
				// output help message to text display
				// output help message to graphics display
			}
			else if (input == "end") {
				// activate any end of turn effects
				if (turnPlayer == 1) {
					turnPlayer = 2;
				}
				else {
					turnPlayer = 1;
				}
			}
			else if (input == "quit") {
				break;
			}
			else if (input == "draw") {
				if (testing) {
				}
			}
			else if (input == "discard") {
				if (testing) {
					int index;
					if (iss >> index) {
					}
				}
			}
			else if (input == "attack") {
				int playerMinion;
				if (iss >> playerMinion) {
					int enemyMinion;
					if (iss >> enemyMinion) {
						// attack selected minion
					}
					else {
						// attack directly
					}
				}
			}
			else if (input == "play") {
				int handCard;
				if (iss >> handCard) {
					int owner;
					if (iss >> owner) {
						int targetCard;
						if (iss >> targetCard) {
							// play card from hand on owner's minion
						}
					}
					else {
						// play card from hand, no target
					}
				}
			}
			else if (input == "use") {
				int minion;
				if (iss >> minion) {
					int owner;
					if (iss >> owner) {
						int targetCard;
						if (iss >> targetCard) {
							// activate effect on owner's minion
						}
					}
					else {
						// play card from hand, no target
					}
				}
			}
			else if (input == "inspect") {
				int minion;
				if (iss >> minion) {
					// display inspected minion owned by turn player
				}
			}
			else if (input == "hand") {
				// display turn player's hand
			}
			else if (input == "board") {
				// display turn player's board
			}
		}
	}

}
