#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Player;

int main(int argc, char *argv[]) {

	Player player1;
	Player player2;

	// load player 1's deck as default.deck
	// load player 2's deck as default.deck
	
	bool testing = false;

	if (argv.size() > 1) {
		for (int i = 1; i < argv.size(); ++i) {
			if (argv[i] == "-deck1" && i != argv.size() - 1) {
				// load deck from file
			}
			else if (argv[i] == "-deck2" && i != argv.size() - 1) {
				// load deck from file
			}
			else if (argv[i] == "-init" && i != argv.size() - 1) {
				// do something to the following argv element
			}
			else if (argv[i] == "-testing") {
				testing = true;
			}
			else if (argv[i] == "-graphics") {
				// enable graphical interface
			}
		}
	}
	
	string input;

	// main game loop
	while (true) {
		// each command on its own line
		getline(cin, input);
		istringstream iss{input};
		if (iss >> input) {
			if (input == "help") {
				// output help message to text display
				// output help message to graphics display
			}
			else if (input == "end") {
			}
			else if (input == "quit") {
				break;
			}
			else if (input == "draw") {
				if (testing) {
				}
			}
			else if (input == "discard") {
				int index;
				if (iss >> index) {
				}
			}
			else if (input == "attack") {
				int playerMinion;
				if (iss >> playerMinion) {
					int enemyMinion;
					if (iss >> enemyMinion) {
					}
					else {
					}
				}
			}
			else if (input == "play") {
				// to do
			}
			else if (input == "use") {
			}
			// to do: add rest of commands
		}
	}

}
