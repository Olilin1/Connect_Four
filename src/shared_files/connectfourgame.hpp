#ifndef CONNECTFOURGAME_H
#define CONNECTFOURGAME_H

#include <vector>
#include <iostream>

class ConnectFourGame
{

private:
    std::vector<std::vector<short>> board;
    short turn;
    short winner;
    short (*player1)(std::vector<std::vector<short>>);
    short (*player2)(std::vector<std::vector<short>>);
    void gameLoop();
    short getWinner();

public:
    ConnectFourGame();
    ConnectFourGame(short (*)(std::vector<std::vector<short>>),
                    short (*)(std::vector<std::vector<short>>));
    std::vector<std::vector<short>> getBoard();
    short getStatus();
    void setPlayer1(short (*ptr)(std::vector<std::vector<short>>));
    void setPlayer2(short (*ptr)(std::vector<std::vector<short>>));
    void startGame();
                    
};

#endif // CONNECTFOURGAME_H
