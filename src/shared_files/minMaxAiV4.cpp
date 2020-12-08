#include "minMaxAiV4.hpp"

short minMaxAiV4(std::vector<std::vector<short>> v){
    Bitboard board(v);

    int index = -1;
    int depth = 23;
    if(board.getMoves() >= 13) depth = 42-board.getMoves();
    int t;

    for(int i = 0; i<7; i++){
        if(board.can_play(i) && board.isWinningMove(i)) return i;
    }


    int alpha = -(43-board.getMoves());
    int beta = 41-board.getMoves(); //42-moves-2+1 for winning;

    std::map<uint64_t,short> m;

    for(int i = 0; i < 7; i++){
        
        if(board.can_play(Bitboard::moveOrder[i])){
            Bitboard board2(board);
            board2.play(Bitboard::moveOrder[i]);
            t = -minMaxAiV4(board2, -beta, -alpha, depth-1, m);
            if(t >= beta) return Bitboard::moveOrder[i];
            if(t > alpha){ 
                alpha = t;
                index = Bitboard::moveOrder[i];
            }
        }
    }
    //std::cout << alpha << ' ' << index << std::endl;
    return index;
}
short minMaxAiV4(Bitboard board, int alpha, int beta, int depth, std::map<uint64_t,short> &m){
    for(int i = 0; i <7; i++){
        if(board.can_play(i) && board.isWinningMove(i))
                return 43-board.getMoves();
    }

    if(board.getMoves() == 42 || depth == 0) return 0;
    int max = 41-board.getMoves();

    if(m.count(board.getKey()) && m[board.getKey()] > alpha) alpha = m[board.getKey()];

    if(beta > max) beta = max;
    if(alpha >= beta) return beta; //No possible moves within [alpha:beta] window
    

    int t;
    int org = alpha;
    for(int i = 0; i < 7; i++){
        if(board.can_play(Bitboard::moveOrder[i])){
            Bitboard board2(board);
            board2.play(Bitboard::moveOrder[i]);
            t = -minMaxAiV4(board2, -beta, -alpha, depth-1, m);
            if(t >= beta){ 
                m[board.getKey()] = t; //We know t > alpha because previously alpha was less than beta
                return t;
            }
            if(t > alpha) alpha = t;
        }
    }
    if(org!=alpha) m[board.getKey()] = alpha;
    return alpha;
}