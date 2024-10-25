#include "minMaxAiV2.hpp"

short minMaxAiV2(std::vector<std::vector<short>> board){
    int count[3] = {0,0,0};
    bool maximize;
    for(int i = 0; i<6; i++){
        for(int j = 0; j<7; j++){
            count[board[i][j]]++;
        }
    }
    maximize = (count[1]==count[2]);
    short move = minMaxAiV2(board, 12, -1000, 1000,  maximize, true);
    return move;
}

short minMaxAiV2(std::vector<std::vector<short>> &board, int depth,int alpha, int beta, bool maximize, bool first){
    if(depth == 0) return 0;
    bool quit = true;
    for(int i = 0; i < 7; i++){
        if(board[0][i] == 0) quit = false;
    }
    if(quit) return 0;

    int index;
    int t;
    if(maximize){

        for(int i = 0; i<7;i++){
            if(board[0][i] != 0) continue;
            for(int j = 5; j >= 0; j--){
                if(board[j][i] == 0){
                    board[j][i] = 1;
                    short t = minMaxGetWinnerV2(board);
                    board[j][i] = 0;
                    if(t==1) return first?i:depth+1;

                    break;
                }
            }
        }

        short maxEval = -1000;
        for(int i = 0; i<4;i++){
            if(board[0][3+i] == 0)
            {
                for (int j = 5; j >= 0; j--)
                {
                    if (board[j][3 + i] == 0)
                    {
                        board[j][3 + i] = 1;
                        //if (first) std::cout << "Searching: " << 3 + i << " At depth: " << depth << std::endl;
                        t = minMaxAiV2(board, depth - 1, alpha, beta, false, false);
                        if (t > maxEval)
                        {
                            maxEval = t;
                            index = 3 + i;
                        }
                        board[j][3 + i] = 0;
                        alpha = std::max(alpha, t);
                        if (beta <= alpha)
                            return first ? index : maxEval;
                        break;
                    }
                }
            }
            if(i==0) continue;
            if(board[0][3-i] != 0) continue;
            for(int j = 5; j >= 0; j--){
                if(board[j][3-i] == 0){
                    board[j][3-i] = 1;
                    //if(first) std::cout << "Searching: " << 3-i<< " At depth: "<<depth<<std::endl;
                    t =minMaxAiV2(board, depth-1, alpha, beta, false, false);
                    if(t> maxEval){
                        maxEval = t;
                        index = 3-i;
                    }
                    board[j][3-i] = 0;
                    alpha = std::max(alpha, t);
                    if(beta <= alpha) return first?index:maxEval;
                    break;
                }
            }

        }
        return first?index:maxEval;
    }
    else{

        for(int i = 0; i<7;i++){
            if(board[0][i] != 0) continue;
            for(int j = 5; j >= 0; j--){
                if(board[j][i] == 0){
                    board[j][i] = 2;
                    short t = minMaxGetWinnerV2(board);
                    board[j][i] = 0;
                    if(t==2) return first?i:-1*(depth+1);

                    break;
                }
            }
        }

        short minEval = 1000;
        for(int i = 0; i<4;i++){
            if (board[0][3 + i] == 0){
                for(int j = 5; j >= 0; j--){
                    if(board[j][3+i] == 0){
                        board[j][3+i] = 2;
                        //if(first) std::cout << "Searching: " << 3+i<< " At depth: "<<depth<<std::endl;
                        t =minMaxAiV2(board, depth-1, alpha, beta, true, false);
                        if(t<minEval){
                            minEval = t;
                            index = 3+i;
                        }
                        board[j][3+i] = 0;
                        beta = std::min(beta, t);
                        if(beta <= alpha) return first? index:minEval;
                        break;
                    }
                }
            }

            if(i==0) continue;
            if(board[0][3-i] != 0) continue;
            for(int j = 5; j >= 0; j--){
                if(board[j][3-i] == 0){
                    board[j][3-i] = 2;
                    //if(first) std::cout << "Searching: " << 3-i<< " At depth: "<<depth<<std::endl;
                    t =minMaxAiV2(board, depth-1, alpha, beta, true, false);
                    if(t<minEval){
                        minEval = t;
                        index = 3-i;
                    }
                    board[j][3-i] = 0;
                    beta = std::min(beta, t);
                    if(beta <= alpha) return first? index:minEval;
                    break;
                }
            }
        }
        return first? index:minEval;
    }
}

short minMaxGetWinnerV2(std::vector<std::vector<short>> &board){
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