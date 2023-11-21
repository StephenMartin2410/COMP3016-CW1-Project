#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

class GameInstance {

private:

	char currentInput;//stores the current input from the player
	int storyLine = 0;//stores the line of the story the player is currently on
	int score = 0;//the players score for individual story lines
	int playerHealth = 10;//the players maximum health
	int playerDamage;//stores the damage the player will take calculated based off their score
	int linenumber;//used to iterate through the lines of the story
	float scorePercent = 0.0f;//holds the score percentage per story line
	int decisionNum;//the line number but for the decision text files
	string line;//stores the temp line being read from the files
	string typingLine;//stores the current line being outputted by the story file
	
public:
	char exitInput = ' ';//stores the char the player presses when the game pauses after finishing
	bool start = false;//whether the game has started
	bool endGame = 0;//whether the game has ended
	void rules() {//outputs the rules and basis of the game to the player if the game has started
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


	int outputStory() {//reads through the story file and prints out the current story line based on the players progress
		try {
			ifstream storyFile("Story.txt");
			linenumber = 0;
			system("cls");
			rules();//outputs the rules here
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
			if (line == "") {
				throw 404;
			}
		}
		catch (...) {//the same exception handling found for the start file
			cout << "Story File not found" << endl << "Please locate Story.txt and paste it into the file directory.";
			cout << "\n" << "Press Enter To Exit: ";
			while (exitInput != '\r') {
				exitInput = _getch();
			}
			exit(0);
		}
		
		return 0;
	}


	int typeTest() {//used to allow the user to type the story line and be given a score based on accuracy. the user can also choose to backspace the characters to correct themselves
		vector<bool> scoreCheck;//a vector used to store whether the letters being typed are correct or incorrect, changes if the user backspaces
		for (int y = 0; y < typingLine.length(); y++) {
			scoreCheck.push_back(false);
		}
		for (int i = 0; i < typingLine.length(); i++) {
			currentInput = _getch();
			while (currentInput == '\r') {//blocks the user from pressing the enter key as it breaks the functionality
				currentInput = _getch();
			}
			if (typingLine[i] == currentInput) {//checks if the user has inputted the correct character
				cout << currentInput;
				if (scoreCheck[i] == false) {//updates the boolean vector to whether the inputted character is true or false
					score++;
					scoreCheck[i] = true;
				}
			}
			else if (currentInput == char(8)) {//allows the user to backspace by backwards iterating i and outputting a backspace to delete the character and overwritting it with a space before backspacing again
				i = i - 2;
				if (i < 0) {
					i = -1;
				}
				cout << currentInput << ' ' << char(8);

			}
			else if (typingLine[i] != currentInput) {//simply outputs the incorrect character that is inputted
				cout << currentInput;
			}
		}
		scorePercent = ((float)score / (float)typingLine.length()) * 100;//calculates the users current story line score based on the percentage of chars that were correctly written
		scoreCheck.clear();//wipes the vector ready for the next story line
		return 0;
	}
	
	
	int Decision() {//used to decide which line needs to be outputted to the user based on whether they performed well or poorly
		ifstream positive("Positive.txt");
		ifstream negative("Negative.txt");
		decisionNum = 0;
		string decisionLine;
		cout << "\n\n" << "Your score is: " << (int)scorePercent << "%" << "\n\n";//outputs the players score percentage
		if (scorePercent > 98) {
			try {
				while (getline(positive, decisionLine)) {//operates the same as the story line getline but with the positive outcome of the story

					if (decisionNum == storyLine - 1) {
						cout << endl << decisionLine << endl;
					}
					decisionNum++;
				}
				if (decisionLine == "") {
					throw 404;
				}
			}
			catch (...) {
				cout << "Positive File not found" << endl << "Please locate Positive.txt and paste it into the file directory.";
				cout << "\n" << "Press Enter To Exit: ";
				while (exitInput != '\r') {
					exitInput = _getch();
				}
				exit(0);
			}
		}
		else {
			try {
				while (getline(negative, decisionLine)) {//operates the same as the story line getline but with the negative outcome of the story

					if (decisionNum == storyLine - 1) {
						cout << endl << decisionLine << endl;
					}
					decisionNum++;
				}
				if (decisionLine == "") {
					throw 404;
				}
			}
			catch (...) {
				cout << "Negative File not found" << endl << "Please locate Negative.txt and paste it into the file directory.";
				cout << "\n" << "Press Enter To Exit: ";
				while (exitInput != '\r') {
					exitInput = _getch();
				}
				exit(0);
			}
			if ((int)scorePercent > 90) {//decides how much health the player should lose this round based on their percentage score
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
			playerHealth = playerHealth - playerDamage;//deals damage to the player
			cout << endl << "You lost " << playerDamage << " health" << endl << "Player health = " << playerHealth << "\n\n";//displays the players current health after damage
			if (playerHealth <= 0) {//if the player dies this message plays
				endGame = true;
				cout << endl << "Congratulations, you had an awful day and you died.";
			}
		}
		if (linenumber == storyLine) {//when the player has reached the end of the story file this message plays
			cout << endl << "Congrats on finishing the game, I hope you enjoyed it. :) Don't forget to go back and try the negative outcomes as well." << endl;
			endGame = true;
		}


		return 0;
	}


};