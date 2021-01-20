#include "minMaxAiV4.hpp"
//This includes a map to store previously calculated positions
short minMaxAiV4(std::vector<std::vector<short>> v){
    Bitboard board(v);

    int index = -1; //Which column to play
    int depth = 23; //How many moves to search
    if(board.getMoves() >= 13) depth = 42-board.getMoves(); //If enough moves have been played then we can search to the end of the game
    int t;

    //If any move allows us to immediately win then obviously play it.
    for(int i = 0; i<7; i++){
        if(board.can_play(i) && board.isWinningMove(i)) return i;
    }


    int alpha = -(43-board.getMoves()); //Lowest possible score we could get
    int beta = 41-board.getMoves(); //42-moves-2+1 for winning;

    std::map<uint64_t,uint8_t> m; //Map to keep track of previously calculated positions

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
    return index;
}

short minMaxAiV4(Bitboard board, int alpha, int beta, int depth, std::map<uint64_t,uint8_t> &m){
    for(int i = 0; i <7; i++){
        if(board.can_play(i) && board.isWinningMove(i))
                return 43-board.getMoves();
    }

    if(board.getMoves() == 42 || depth == 0) return 0;
    int max = 41-board.getMoves();//Maximum possible score we can get

    if(m.count(board.getKey()) && m[board.getKey()] > alpha) alpha = m[board.getKey()];

    if(beta > max) beta = max;
    if(alpha >= beta) return beta; //No possible moves within [alpha:beta] window
    

    int t;
    int org = alpha; //A way to keep track of wheter or not alpha has changed
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
    if(org!=alpha) m[board.getKey()] = alpha; //Alpha is known to be the best possible score I think?
    return alpha;
}