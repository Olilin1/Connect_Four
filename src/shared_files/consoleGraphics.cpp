#include"consoleGraphics.hpp"
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