#include <stdio.h>

char board[3][3] = {{' ', ' ', 'X'},
                    {' ', 'X', ' '},
                    {'X', ' ', ' '}};

char check_win(){

    char winner;

    for(int i = 0; i < 3; i++){
        if(board[i][1] != ' ' && board[i][1] == board[i][0] && 
           board[i][1] == board[i][2]){
            winner = board[i][1];
            return winner;
        }
        else if(board[1][i] != ' ' && board[1][i] == board[0][i] && 
                board[1][i] == board[2][i]){
            winner = board[1][i];
            return winner;
        }
    }
    if(board[1][1] != ' ' && ((board[1][1] == board[0][0] && 
                               board[1][1] == board[2][2]) || 
                              (board[1][1] == board[2][0] && 
                               board[1][1] == board[0][2]))){
        winner = board[1][1];
        return winner;
    }
    return 0;
}


int main(){

    printf("%c", check_win());


    return 0;
}