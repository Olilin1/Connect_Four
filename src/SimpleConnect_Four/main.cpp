#include "../shared_files/gameLibrary.hpp"

#include <iostream>

//Outputs who won in the end
void displayWinner(short winner){
    using namespace std;
    if(winner == 1) cout << "Player 1 wins!" << endl;
    else if (winner == 2) cout << "Player 2 wins" << endl;
    else cout << "It's a TIE!" << endl;
    return;
}


int main(int argc, char* argv[]) {
    //Initialise a game, switch the functionpointers to whitchever AI/player you want, leave consoleGraphics in place.
    ConnectFourGame myGame(sequentialAi, randomAi, consoleGraphics);
    myGame.startGame();
    displayWinner(myGame.getStatus());
    return 0;
}