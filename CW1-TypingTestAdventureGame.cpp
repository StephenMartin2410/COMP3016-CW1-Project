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
    try {
        ifstream startFile("Start.txt");
        if (startFile.is_open()) {
            while (getline(startFile, line)) {
                for (int i = 0; i < line.length(); i++) {
                    if (line[i] == '#') {
                        cout << char(219);
                    }
                    else {
                        cout << line[i];
                    }
                }
                cout << endl;
            };
        };
        startFile.close();
        if (line == "") {
            throw 404;
        }
    }
    catch (...) {
        cout << "Start File not found" << endl << "Please locate Start.txt and paste it into the file directory.";
        cout << "\n" << "Press Enter To Exit: ";
        while (exitInput != '\r') {
            exitInput = _getch();
        }
        exit(0);
    }
    while (1) {

        startGame.startGame();

        if (startGame.start == true) {
            startGame.outputStory();
            startGame.typeTest();
            startGame.Decision();
        }


        //startGame.endGame = true;
        if (startGame.endGame == true) {
            cout << "\n" << "Press Enter To Exit: " ;
            while (exitInput != '\r') {
                exitInput = _getch();
            }
            break;

            
            
        }
    }

}
