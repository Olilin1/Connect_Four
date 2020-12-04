#ifndef CONNECTFOURGAME_H
#define CONNECTFOURGAME_H

#include <vector>
#include <iostream>

class ConnectFourGame
{
typedef short(*playerFunc)(std::vector<std::vector<short>>);
typedef void(*graphicsFunc)(std::vector<std::vector<short>>);
private:
    std::vector<std::vector<short>> board;
    short turn;
    short winner;
    short (*player1)(std::vector<std::vector<short>>);
    short (*player2)(std::vector<std::vector<short>>);
    graphicsFunc graphics;
    void gameLoop();
    short getWinner();

public:
    ConnectFourGame(playerFunc = nullptr,
                    playerFunc = nullptr,
                    graphicsFunc = nullptr);
    std::vector<std::vector<short>> getBoard();
    short getStatus();
    short getTurn();
    void setPlayer1(playerFunc);
    void setPlayer2(playerFunc);
    void setGraphics(graphicsFunc);
    void startGame();
                    
};

#endif // CONNECTFOURGAME_H
