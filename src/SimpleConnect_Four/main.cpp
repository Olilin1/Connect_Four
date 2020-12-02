#include "../shared_files/gameLibrary.hpp"

#include <iostream>

void displayWinner(short winner){
    using namespace std;
    if(winner == 1) cout << "Player 1 wins!" << endl;
    else if (winner == 2) cout << "Player 2 wins" << endl;
    else cout << "It's a TIE!" << endl;
    return;
}
void consoleGraphics(std::vector<std::vector<short>> board){
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    ConnectFourGame myGame(sequentialAi, randomAi);
    myGame.startGame();
    displayWinner(myGame.getStatus());
    return 0;
}