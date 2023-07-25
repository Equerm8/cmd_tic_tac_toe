#include <stdio.h>
#include <string.h>

void create_board(char board[3][3]){
    printf("   1   2   3 ", board[0][0], board[0][1], board[0][2]);
    printf("\n1  %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n  ---|---|----");
    printf("\n2  %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n  ---|---|----");
    printf("\n3  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

void create_buttons(short value, char writings[]){
    char toWrite[256] = "";
    int j = 0;
    for(int i = 0; i < value; i++){
        while (writings[j] != ' ' && writings[j] != '\0') {
            strncat(toWrite, &writings[j], 1);
            j++;
        }

        printf("|----------------------|\n");
        printf("|%s\n", toWrite);
        printf("|----------------------|\n\n");

        toWrite[0] ='\0';
        j++;
    }
    printf("Option: ");
}
