#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//class Player;

int main(int argc, char *argv[]) {

	//Player player1;
	//Player player2;
	ifstream initFile;
	string initFileName = "";
	string player1Deck = "default.deck";
	string player2Deck = "default.deck";
	
	bool testing = false;

	if (argc > 1) {
		vector <string> args{argv, argv + argc};
		for (int i = 1; i < argc; ++i) {
			if (args[i] == "-deck1" && i != argc - 1) {
				player1Deck = args[i + 1];
			}
			else if (args[i] == "-deck2" && i != argc - 1) {
				player1Deck = args[i + 1];
			}
			else if (args[i] == "-init" && i != argc - 1) {
				initFileName = args[i + 1];
			}
			else if (args[i] == "-testing") {
				testing = true;
			}
			else if (args[i] == "-graphics") {
				// enable graphical interface
			}
		}
	}
	// load init file if it exists
	if (initFileName.length() > 0) {
		initFile.open(initFileName);
	}
	// to do: load player decks from file stream
	string input;
	int turnPlayer = 1;

	// main game loop
	while (true) {
		// default to cin after end of -init file
		if (!initFile.eof()) {
			getline(initFile, input);
		}
		else {
			getline(cin, input);
		}
		// each input on its own line
		istringstream iss{input};
		if (iss >> input) {
			if (input == "help") {
				// output help message to text display
				// output help message to graphics display
				cout << "This is a placeholder help message." << endl;
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
