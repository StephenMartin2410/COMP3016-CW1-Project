#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Typing.h"
using namespace std;


int main()
{
    string line;
    char exitInput = ' ';
    ifstream startFile ("Start.txt");
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
    GameInstance startGame;
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
