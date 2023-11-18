#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

class GameInstance {

private:
	bool start = false;
	char currentInput;
	int storyLine = 0;
	int score = 0;
	string line;
	string typingLine;
	
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
				<< "Have Fun!\n\n";
			}
	}

	int startGame() {
		if (start == false) {
			currentInput = _getch();
			if (currentInput == ' ') {
				start = true;
			}
		}

		return 0;
	}
	int outputStory() {
		ifstream storyFile("Story.txt");
		int linenumber = 0;
		system("cls");
		rules();
		cout << "\n\n" << "Your score is: " << score << "\n\n";
		cout << "Type out the following line: " << "\n\n";
		while (getline(storyFile, line)) {
			
			if (storyLine == linenumber) {
				cout << line << endl;
				typingLine = line;
			}
			 linenumber++;
		}

		storyLine++;
		return 0;
	}
	int typeTest() {
		vector<bool> scoreCheck;
		for (int y = 0; y < typingLine.length(); y++) {
			scoreCheck.push_back(false);
		}
		for (int i = 0; i < typingLine.length(); i++) {
			currentInput = _getch();
			if (typingLine[i] == currentInput) {
				cout << currentInput;
				if (scoreCheck[i] == false) {
					score++;
					scoreCheck[i] = true;
				}
				//cout << score;
			}
			else if (currentInput == char(8)) {
				i = i - 2;
				if (i < 0) {
					i = -1;
				}
				cout << currentInput << ' ' << char(8);

			}
			else if (typingLine[i] != currentInput) {
				cout << currentInput;
			}
		}
		scoreCheck.clear();
		return 0;
	}
	


};