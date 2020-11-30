#ifndef CONNECTFOURGAME_H
#define CONNECTFOURGAME_H

#include <vector>

class ConnectFourGame
{

private:
    std::vector<std::vector<short>> board;
    short turn;
    short winner;
    unsigned short (*player1)(std::vector<std::vector<short>>);
    unsigned short (*player2)(std::vector<std::vector<short>>);
    void gameLoop();
    short getWinner();

public:
    ConnectFourGame(unsigned short (*ptr1)(std::vector<std::vector<short>>),
                    unsigned short (*ptr2)(std::vector<std::vector<short>>));
};

#endif // CONNECTFOURGAME_H
