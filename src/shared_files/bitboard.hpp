#ifndef BITBOARD_H
#define BITBOARD_H
#include <stdint.h>
#include <vector>

class Bitboard{
private:
    uint64_t position, mask;
    unsigned int moves;



public:
    Bitboard();
    Bitboard(std::vector<std::vector<short>>);
    bool can_play(int);
    void play(int);
    bool isWinningMove(int);
    int getMoves();
    uint64_t getKey();

    static uint64_t top_mask(int);
    static uint64_t bottom_mask(int);
    static uint64_t column_mask(int);
    static uint64_t coordinate_mask(int, int);
    static bool alignment(uint64_t);
    static const std::vector<int> moveOrder;

};

#endif