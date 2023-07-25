#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "player.h"
#include "visualisation.h"

void board_clear(char board[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

char check_win(char board[3][3]){

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

void game(Player p1, Player p2, char board[3][3], char option, char currentGameState[]){

    board_clear(board);
    bool end = false; bool m = false;
    int row, column;
    char winner;
    char moveCounter = '1';

    // If first turn is players 1 than currTurn = 1
    bool currTurn = false;
    if(p1.turn) {
        currTurn = true;
    }
    else{
        currTurn = false;
    }

    while(!end){

        system("cls");
        printf("Type 0 to go back to menu\n\n");
        printf("MOVE %c\n\n", moveCounter);
        create_board(board);

        if(currTurn){
            printf("\n%c turn", p1.symbol);
            printf("\nType choosen coordinates");
            printf("\nROW: ");
            scanf("%d", &row);
            if(row == 0){
                end = true;
                m = true;
                option = '1';
                continue;
            }
            else if(row < 1 || row > 3) continue;
            printf("\nCOLUMN: ");
            scanf("%d", &column);
            if(column == 0){
                end = true;
                m = true;
                option = '1';
                continue;
            }
            else if(column < 1 || column > 3) continue;
            if(board[row-1][column-1] != ' ') continue;
            board[row-1][column-1] = p1.symbol;
            currTurn = false;
        }

        else{
            printf("\n%c turn", p2.symbol);
            printf("\nType choosen coordinates");
            printf("\nROW: ");
            scanf("%d", &row);
            if(row == 0){
                end = true;
                m = true;
                option = '1';
                continue;
            }
            if(row < 1 || row > 3) continue;
            printf("COLUMN: ");
            scanf("%d", &column);
            if(column == 0){
                end = true;
                m = true;
                option = '1';
                continue;
            }
            if(column < 1 || column > 3) continue;
            if(board[row-1][column-1] != ' ') continue;
            board[row-1][column-1] = p2.symbol;
            currTurn = true;
        }

        winner = check_win(board);
        if(winner || moveCounter == '9')end = true;
        else moveCounter++;
    }

    do{
        if(!m){
            system("cls");
            create_board(board);
            if(winner) printf("\n!!! PLAYER %c HAS WON AFTER %c MOVES!!!\n\n", winner, moveCounter);
            else printf("\nTIE\n");
            printf("\n1. Menu | 2. Restart | 3. Exit\n");
            printf("Option: ");
            scanf("%c", &option);
        }
        switch(option){
            case '1':
                strcpy(currentGameState, "menu");
                break;

            case '2':
                strcpy(currentGameState, "game");
                break;

            case '3':
                strcpy(currentGameState, "exit");
                break;
        }
    }while((int)option < 49 || (int)option > 51);
}
