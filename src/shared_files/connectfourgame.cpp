#include "connectfourgame.hpp"

ConnectFourGame::ConnectFourGame(){

}

ConnectFourGame::ConnectFourGame(short (*ptr1)(std::vector<std::vector<short>>),
                                short (*ptr2)(std::vector<std::vector<short>>)){
    definedEndfunction = false;
    player1 = ptr1;
    player2 = ptr2;
    turn = 1;
    winner = 0;
    board.resize(6);
    for(int i = 0; i < 6; i++){
        board[i].resize(7);
    }
    gameLoop();
}

std::vector<std::vector<short>> ConnectFourGame::getBoard(){
    return board;
}

short ConnectFourGame::getStatus(){
    return winner;
}

void ConnectFourGame::gameLoop(){
    using namespace std;
    while(winner == 0){ //Medans det inte finns någon vinnare
        short placement = turn == 1 ? player1(board) : player2(board); //Få vald kolumn från spelaren vars tur det är
        if(placement < 0 || placement > 6) continue;
        if(board[0][placement] == 0){ //Om den kolumnen inte är full
            int i = 5;
            while(board[i][placement] != 0){ 
                i--;
            }
            board[i][placement] = turn; //Placera då en markör överst i kolumnen
            winner = getWinner(); //Kolla om det har uppstått en vinnare
            turn = turn == 1 ? 2:1; //Byt vems tur det är
        }
    }
    
    if(definedEndfunction) endFunc(winner);
}

short ConnectFourGame::getWinner(){
    //Check if anyone has won
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
            for(int offset = 0; i+offset < 6 && j - offset >= 0; offset++){//Kolla andra diagonalem
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

