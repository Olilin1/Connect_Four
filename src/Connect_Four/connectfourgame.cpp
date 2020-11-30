#include "connectfourgame.h"

ConnectFourGame::ConnectFourGame(unsigned short (*ptr1)(std::vector<std::vector<short>>),
                unsigned short (*ptr2)(std::vector<std::vector<short>>)){
    player1 = ptr1;
    player2 = ptr2;
    turn = 1;
    winner = 0;
    board.resize(7);
    gameLoop();
}

void ConnectFourGame::gameLoop(){
    while(winner == 0){
        short placement = turn == 1 ? player1(board) : player2(board);
        if(board[placement].size() < 6){
            board[placement].push_back(turn);
            turn = turn==1 ? 2:1;
            winner = getWinner();
        }
    }
}

short getWinner(){
    //Check if anyone has won
    return 0;
}
