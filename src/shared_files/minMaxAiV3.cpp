#include "minMaxAiV3.hpp"

short minMaxAiV3(std::vector<std::vector<short>> v){
    Bitboard board(v);

    int index = -1;
    int depth = 19;
    if(board.getMoves() >= 20) depth = 50;
    int t;

    for(int i = 0; i<7; i++){
        if(board.can_play(i) && board.isWinningMove(i)) return i;
    }

    int max = depth-2;
    int alpha = -1000;
    int beta = max;

    for(int i = 0; i < 7; i++){
        
        if(board.can_play(Bitboard::moveOrder[i])){
            Bitboard board2(board);
            board2.play(Bitboard::moveOrder[i]);
            t = -minMaxAiV3(board2, -beta, -alpha, depth-1);
            if(t >= beta) return Bitboard::moveOrder[i];
            if(t > alpha){ 
                alpha = t;
                index = Bitboard::moveOrder[i];
            }
        }
    }
    return index;
}
short minMaxAiV3(Bitboard board, int alpha, int beta, int depth){
    if(board.getMoves() == 42 || depth == 0) return 0;
    //std::cout << "Depth: " << depth << '\n';

    for(int i = 0; i <7; i++){
        if(board.can_play(i) && board.isWinningMove(i)) return depth;
    }

    int max = depth-2;

    if(beta > max){
        beta = max;
        if(alpha >= beta) return beta; //No possible moves within [alpha:beta] window
    }

    int t;
    for(int i = 0; i < 7; i++){
        if(board.can_play(Bitboard::moveOrder[i])){
            Bitboard board2(board);
            board2.play(Bitboard::moveOrder[i]);
            t = -minMaxAiV3(board2, -beta, -alpha, depth-1);
            if(t >= beta) return t;
            if(t > alpha) alpha = t;
        }
    }
    return alpha;
}