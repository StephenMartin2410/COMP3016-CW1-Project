#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

class TypingInstance {

private:
	bool start = false;
	char currentInput;
	int storyLine = 0;
	
public:
	bool endGame = 0;
	void rules() {
		if (start == true) {
			system("cls");
			cout << "Here are the rules of the game:" << endl;
			cout << "This is a typing adventure game in which your typing score" << endl
				<< "will impact the decisions you make througout the story. " << endl
				<< "For example, if you were to score very badly in a battle with a monster" << endl
				<< "then the monster may kill or badly injure you and you'll lost health points." << endl
				<< "But if you were to score perfectly on the typing, then the monster will be slain." << endl
				<< "Have Fun!\n\n\n\n\n\n";
			}
	}

	int startGame() {
		if (start == false) {
			currentInput = _getch();
			if (currentInput == ' ') {
				start = true;
				rules();
			}
		}

		return 0;
	}
	int outputStory() {
		ifstream storyFile("Story.txt");
		string line;
		int linenumber = 0;
		while (getline(storyFile, line)) {
			
			if (storyLine == linenumber) {
				cout << line;
			}
			 linenumber++;
		}

		endGame = true;
		return 0;
	}



};