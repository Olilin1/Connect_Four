#include "connectfourgame.hpp"
#include "randomAi.hpp"
#include "humanConsolePlayer.hpp"
#include <iostream>

void displayWinner(short winner){
    using namespace std;
    if(winner == 1) cout << "Player 1 wins!" << endl;
    else if (winner == 2) cout << "Player 2 wins" << endl;
    else cout << "It's a TIE!" << endl;
}

int main(int argc, char* argv[]) {
    ConnectFourGame myGame(humanConsolePlayer, randomAi);
    displayWinner(myGame.getStatus());
    return 0;
}