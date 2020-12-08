#include "bitboard.hpp"


const std::vector<int> Bitboard::moveOrder = {3,4,2,5,1,6,0};

Bitboard::Bitboard() : position{0}, mask{0}, moves{0} {}

Bitboard::Bitboard(std::vector<std::vector<short>> v) : position{0}, mask{0}, moves{0} {
    std::vector<int> turn(3);
    for(int i = 0; i<6; i++){
        for(int j = 0; j<7; j++){
            turn[v[i][j]]++;
        }
    }
    bool player1 = turn[2]==turn[1];

    for(int i = 0; i<6; i++){
        for(int j = 0; j<7; j++){
            if(v[i][j] == 1){
                moves++;
                mask |= coordinate_mask(i, j);
                if(player1) position |= coordinate_mask(i, j);
            }
            else if(v[i][j] == 2){
                moves++;
                mask |= coordinate_mask(i, j);
                if(!player1) position |= coordinate_mask(i, j);
            }
        }
    }
}

uint64_t Bitboard::top_mask(int col){
    return (1LL << 5) << (col*7);
}
uint64_t Bitboard::bottom_mask(int col){
    return 1LL << (col*7);
}
uint64_t Bitboard::column_mask(int col){
    return ((1LL<<6)-1) << (col*7);
}

int Bitboard::getMoves(){
    return moves;
}

uint64_t Bitboard::coordinate_mask(int row, int col){
    return (1LL << (5-row)) << (col*7);
}

bool Bitboard::can_play(int col){
    return (mask & top_mask(col)) == 0;
}

void Bitboard::play(int col){
    position ^= mask;
    mask |= mask + bottom_mask(col);
    moves++;
}

bool Bitboard::isWinningMove(int col) 
      {
        uint64_t new_position = position; 
        new_position |= (mask + bottom_mask(col)) & column_mask(col);
        return alignment(new_position);
      }

uint64_t Bitboard::getKey(){
    return position + mask;
}

bool Bitboard::alignment(uint64_t pos){

    //Vågrät
    uint64_t m = pos & (pos >> 7);
    if(m & (m >> (2*7))) return true;//Why not move all three steps at once? Because 1110111 :)

    //Lodrät
    m = pos & (pos >> 1);
    if(m & (m >> 2)) return true;

    //Positiva diagonalen
    m = pos & (pos >> 8);
    if(m & (m >> (2*8))) return true;

    //Neagativa diagonalen
    m = pos & (pos >> 6);
    if(m & (m >> (2*6))) return true;

    return false;
}