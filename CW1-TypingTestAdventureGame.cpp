#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Typing.h"
using namespace std;


int main()
{
    char exitInput = ' ';
    string line;
    GameInstance startGame;
    try { //This try statement is used to attempt to output the start screen of the game.
        ifstream startFile("Start.txt");
        if (startFile.is_open()) {
            while (getline(startFile, line)) {
                for (int i = 0; i < line.length(); i++) {
                    if (line[i] == '#') {
                        cout << char(219);//hashtag is replaced with an ascii character to look nicer on output.
                    }
                    else {
                        cout << line[i];
                    }
                }
                cout << endl;
            };
        };
        startFile.close();
        if (line == "") {//if the files first line returns empty then the program assumes either the file is missing or the file is incorrect and throws an exception.
            throw 404;
        }
    }
    catch (...) {
        cout << "Start File not found" << endl << "Please locate Start.txt and paste it into the file directory.";
        cout << "\n" << "Press Enter To Exit: ";
        while (exitInput != '\r') {
            exitInput = _getch();
        }
        exit(0);//exits the program.
    }
    while (1) {//this is the game loop that keeps the game from stopping until the player dies or reaches the end of the game.

        startGame.startGame();//checks if the player has pressed space to start the game and initiates the start boolean. Also pauses the game after every loop.

        if (startGame.start == true) {//runs if the game has started.
            startGame.outputStory();
            startGame.typeTest();
            startGame.Decision();
        }


        if (startGame.endGame == true) {//outputs if the game ends.
            cout << "\n" << "Press Enter To Exit: " ;
            while (exitInput != '\r') {
                exitInput = _getch();
            }
            break;

            
            
        }
    }

}
