#include "randomAi.hpp"
short randomAi(std::vector<std::vector<short>> board){
    srand(time(NULL));
    return rand() % 7;
}