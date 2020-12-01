#include "sequentialAi.hpp"

short sequentialAi(std::vector<std::vector<short>> board){
    for(int i = 0; i < 7; i++){
        if(board[0][i] == 0) return i;
    }
    std::cout << "End reached";
}