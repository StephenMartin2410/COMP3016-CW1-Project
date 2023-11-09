#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string line;
    //cout << "Hello World!\n";
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
    

}
