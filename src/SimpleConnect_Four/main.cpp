#include "../shared_files/gameLibrary.hpp"

#include <iostream>

void displayWinner(short winner){
    using namespace std;
    if(winner == 1) cout << "Player 1 wins!" << endl;
    else if (winner == 2) cout << "Player 2 wins" << endl;
    else cout << "It's a TIE!" << endl;
    return;
}

int main(int argc, char* argv[]) {
    ConnectFourGame myGame(sequentialAi, randomAi);
    displayWinner(myGame.getStatus());
    return 0;
}