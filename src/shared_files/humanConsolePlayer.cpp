#include "humanConsolePlayer.hpp"

//A function that allows a human to play using the console
short humanConsolePlayer(std::vector<std::vector<short>> board){
    using namespace std;
    int kolumn;
    cout << endl;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
    cin >> kolumn;
    return kolumn;
}