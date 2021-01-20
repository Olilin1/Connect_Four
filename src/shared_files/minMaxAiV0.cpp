#include "minMaxAiV0.hpp"

short minMaxAiV0(std::vector<std::vector<short>> board){
    int count[3] = {0,0,0};
    bool maximize;
    for(int i = 0; i<6; i++){
        for(int j = 0; j<7; j++){
            count[board[i][j]]++;
        }
    }
    maximize = (count[1]==count[2]); //Determine who's turn it is.
    short move = minMaxAiV0(board, 6, maximize, true);
    return move; //Return which column to play in
}

//Start a minimax search. With first being wheter or not this is the first iteration because in that case return column to play instead of
//minimax-value
short minMaxAiV0(std::vector<std::vector<short>> &board, int depth, bool maximize, bool first){
    short winner = minMaxGetWinnerV0(board); //Check if anyone has won
    if(winner == 3) return 0;
    if(winner == 2) return -1*(depth+1);
    if(winner == 1) return depth+1;
    if(depth == 0) return 0;
    int index;
    int t;
    if(maximize){ //Do we want to maximize or minimize the score?
        //The rest is just standard minimax procedure
        short maxEval = -1000;
        for(int i = 0; i<7;i++){
            if(board[0][i] != 0) continue;
            for(int j = 5; j >= 0; j--){
                if(board[j][i] == 0){
                    board[j][i] = 1;
                    t =minMaxAiV0(board, depth-1, false, false);
                    if(t> maxEval){
                        maxEval = t;
                        index = i;
                    }
                    board[j][i] = 0;
                    break;
                }
            }
        }
        return first?index:maxEval;
    }
    else{
        short minEval = 1000;
        for(int i = 0; i<7;i++){
            if(board[0][i] != 0) continue;
            for(int j = 5; j >= 0; j--){
                if(board[j][i] == 0){
                    board[j][i] = 2;
                    t =minMaxAiV0(board, depth-1, true, false);
                    if(t<minEval){
                        minEval = t;
                        index = i;
                    }
                    board[j][i] = 0;
                    break;
                }
            }
        }
        return first? index:minEval;
    }
}

//Copied from connectfourgame.cpp
short minMaxGetWinnerV0(std::vector<std::vector<short>> &board){ 
    short player1, player2;
    
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            player1 = 0;
            player2 = 0;
            for(int offset = i; offset < 6; offset++){//Kolla lodrät
                switch (board[offset][j])
                {
                    case 0:
                        player1 = 0;
                        player2 = 0;
                    break;
                    case 1:
                        player1 += 1;
                        player2 = 0;
                    break;
                    case 2:
                        player1 = 0;
                        player2 += 1;
                    break;
                    default:
                    break;
                }
                if(player1 == 4) return 1;
                if(player2 == 4) return 2;
            }

            player1 = 0;
            player2 = 0;
            for(int offset = j; offset < 7; offset++){//Kolla vågrät
                switch (board[i][offset])
                {
                    case 0:
                        player1 = 0;
                        player2 = 0;
                    break;
                    case 1:
                        player1 += 1;
                        player2 = 0;
                    break;
                    case 2:
                        player1 = 0;
                        player2 += 1;
                    break;
                    default:
                    break;
                }
                if(player1 == 4) return 1;
                if(player2 == 4) return 2;
            }

            player1 = 0;
            player2 = 0;
            for(int offset = 0; i+offset < 6 && j + offset < 7; offset++){//Kolla diagonalt
                switch (board[i+offset][j+offset])
                {
                    case 0:
                        player1 = 0;
                        player2 = 0;
                    break;
                    case 1:
                        player1 += 1;
                        player2 = 0;
                    break;
                    case 2:
                        player1 = 0;
                        player2 += 1;
                    break;
                    default:
                    break;
                }
                if(player1 == 4) return 1;
                if(player2 == 4) return 2;
            }

            player1 = 0;
            player2 = 0;
            for(int offset = 0; i+offset < 6 && j - offset >= 0; offset++){//Kolla andra diagonalen
                switch (board[i+offset][j-offset])
                {
                    case 0:
                        player1 = 0;
                        player2 = 0;
                    break;
                    case 1:
                        player1 += 1;
                        player2 = 0;
                    break;
                    case 2:
                        player1 = 0;
                        player2 += 1;
                    break;
                    default:
                    break;
                }
                if(player1 == 4) return 1;
                if(player2 == 4) return 2;
            }

        }
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            if(board[i][j] == 0) return 0; //Check that it's not a tie
        }
    }
    return 3;
}