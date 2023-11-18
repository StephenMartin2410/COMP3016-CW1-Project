#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Typing.h"
using namespace std;


int main()
{
    string line;
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
        startGame.outputStory();
        startGame.typeTest();




        //startGame.endGame = true;
        if (startGame.endGame == true) {
            break;
        }
    }

}
