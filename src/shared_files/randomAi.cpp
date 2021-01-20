#include "randomAi.hpp"

//A simple AI that just plays random available moves
short randomAi(std::vector<std::vector<short>> board){
    _sleep(1200);
    srand(time(NULL));
    short t = rand() % 7;
    while(board[0][t] != 0) t = rand() % 7;
    return t;
}