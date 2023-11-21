#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

class GameInstance {

private:

	char currentInput;
	int storyLine = 0;
	int score = 0;
	int playerHealth = 10;
	int playerDamage;
	int linenumber;
	float scorePercent = 0.0f;
	int decisionNum;
	string line;
	string typingLine;
	
public:

	bool start = false;
	bool endGame = 0;
	void rules() {
		if (start == true) {
			system("cls");
			cout << "Here are the rules of the game:" << endl;
			cout << "This is a typing adventure game in which your typing score" << endl
				<< "will impact the decisions you make througout the story.         " << endl
				<< "For example, if you were to score very badly in a situation then" << endl
				<< "the outcome will be worse and may impact the story in a negative way." << endl
				<< "But if you were to score perfectly on the typing, then the outcome may be positive." << endl
				<< "Have Fun!\n\n";
			}
	}

	int startGame() {
		if (start == false && endGame == false) {
			currentInput = _getch();
			if (currentInput == ' ') {
				start = true;
			}
		}
		else {
			cout << "\n\n\n" << "Press Enter To Continue: " << endl;
			while (currentInput != '\r') {
				currentInput = _getch();
			}
		}

		return 0;
	}


	int outputStory() {
		ifstream storyFile("Story.txt");
		linenumber = 0;
		system("cls");
		rules();
		//cout << "\n\n" << "Your score is: " << (int)scorePercent  << "%" << "\n\n";
		scorePercent = 0.0f;
		score = 0;
		cout << "Type out the following line to completion: " << "\n\n";
		while (getline(storyFile, line)) {
			
			if (storyLine == linenumber) {
				cout << line << endl;
				typingLine = line;
			}
			 linenumber++;
		}
		storyLine++;
		/*if (linenumber == storyLine) {
			cout << endl << "Congrats on finishing the game, I hope you enjoyed it. :) Don't forget to go back and try the negative outcomes as well." << endl;
			endGame = true;
		}*/
		
		return 0;
	}


	int typeTest() {
		vector<bool> scoreCheck;
		for (int y = 0; y < typingLine.length(); y++) {
			scoreCheck.push_back(false);
		}
		for (int i = 0; i < typingLine.length(); i++) {
			currentInput = _getch();
			while (currentInput == '\r') {
				currentInput = _getch();
			}
			if (typingLine[i] == currentInput) {
				cout << currentInput;
				if (scoreCheck[i] == false) {
					score++;
					scoreCheck[i] = true;
				}
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
		scorePercent = ((float)score / (float)typingLine.length()) * 100;
		scoreCheck.clear();
		return 0;
	}
	
	
	int Decision() {
		ifstream positive("Positive.txt");
		ifstream negative("Negative.txt");
		decisionNum = 0;
		string decisionLine;
		cout << "\n\n" << "Your score is: " << (int)scorePercent << "%" << "\n\n";
		if (scorePercent > 98) {
			while (getline(positive, decisionLine)) {

				if (decisionNum == storyLine - 1) {
					cout << endl << decisionLine << endl;
				}
				decisionNum++;
			}
		}
		else {

			while (getline(negative, decisionLine)) {

				if (decisionNum == storyLine - 1) {
					cout << endl << decisionLine << endl;
				}
				decisionNum++;
			}
			if ((int)scorePercent > 90) {
				playerDamage = 1;
			}
			else if ((int)scorePercent > 70) {
				playerDamage = 2;
			}
			else if ((int)scorePercent > 50) {
				playerDamage = 4;
			}
			else if ((int)scorePercent > 30) {
				playerDamage = 6;
			}
			else if ((int)scorePercent <= 30) {
				playerDamage = 10;
			}
			playerHealth = playerHealth - playerDamage;
			cout << endl << "You lost " << playerDamage << " health" << endl << "Player health = " << playerHealth << "\n\n";
			if (playerHealth <= 0) {
				endGame = true;
				cout << endl << "Congratulations, you had an awful day and you died.";
			}
		}
		if (linenumber == storyLine) {
			cout << endl << "Congrats on finishing the game, I hope you enjoyed it. :) Don't forget to go back and try the negative outcomes as well." << endl;
			endGame = true;
		}


		return 0;
	}


};