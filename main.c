#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// To do list
// 1. Check if same symbol is on desired coordinates
// 2. settings, saves etc.
// 3. Analyze game
// 4. Points and loading it

// Navigating through game
char option = -1;
char currentGameState[9] = "menu";

// Collecting trash
char enter;

// Initializing board to play
char board[3][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '}};

// Players
typedef struct
{
    char symbol;
    char occupiedWindows[10];
    unsigned int points;
    bool turn;
}Player;

// Initializing players
Player p1 = {'X', "", 0, 1};
Player p2 = {'O', "", 0, 0};


// All related to the menu
void menu();

// All related to the settings
void settings();

// Initializing the game
void game();

// Check if one of the players won
char check_win();

// Automated board creation
void create_board();

// Automated button creation
void create_buttons(short value, char writings[]);

int main(){

    // Warning of the clearing out the cmd window
    printf("\n\n!!!  WARNING  !!!\n\n");
    printf("This game will CLEAR OUT your CMD\n");
    printf("Do you agree? 1 (yes) / 0 (no): ");
    bool approval = 0;
    scanf("%d", &approval);
    if(!approval) return 0;

    while(true){

        // Menu
        if(strcmp(currentGameState, "menu") == 0){
            menu();
        }

        else if(strcmp(currentGameState, "game") == 0){
            game();
            return 0;
        }

        else if(strcmp(currentGameState, "load") == 0){
            //load();
        }

        else if(strcmp(currentGameState, "settings") == 0){
            settings();
        }

        else if(strcmp(currentGameState, "exit") == 0){
            system("cls");
            return 0;
        }
        
        // Settings
        else if(strcmp(currentGameState, "symbols") == 0){
            system("cls");

            printf("1st player symbol: ");
            scanf("%c", &enter);
            scanf("%c", &p1.symbol);
            scanf("%c", &enter);
            system("cls");

            printf("2nd player symbol: ");
            scanf("%c", &p2.symbol);
            scanf("%c", &enter);
            strcpy(currentGameState, "settings");
        }

        else if(strcmp(currentGameState, "firstTurn") == 0){
            char pft = ' ';
            do{
                pft = ' ';
                system("cls");
                printf("Choose player with 1st turn.\n");
                printf("To do this type symbol of the player\n");
                printf("1st player: %c | 2nd player: %c\n", p1.symbol, p2.symbol);
                scanf("Player with first turn: "); scanf("%c", &pft);
                scanf("%c", &enter);
               
            }while(pft != p1.symbol && pft != p2.symbol);
            if(p1.symbol == pft) {
                p1.turn = 1;
                p2.turn = 0;
            }
            else if(p2.symbol == pft){
                p1.turn = 0;
                p2.turn = 1;
            }
            
            strcpy(currentGameState, "settings");
        }
    }

    return 0;
}

// Menu, settings etc.
void menu(){
    char menuOptions[] = "1_START 2_LOAD_GAME 3_SETTINGS 4_EXIT";

    do{
        system("cls");
        printf("M E N U\n\n");
        create_buttons(4, menuOptions);
        scanf("%c", &option);
        switch(option){
            case '1':
                strcpy(currentGameState, "game");
                break;
            
            case '2':
                strcpy(currentGameState, "load");
                break;

            case '3':
                strcpy(currentGameState, "settings");
                break;
            
            case '4':
                strcpy(currentGameState, "exit");
                break;
        }
    }while((int)option < 49 || (int)option > 52);
    
}

void settings(){
    char settingsOptions[] = "1_SYMBOLS 2_FIRST_TURN 3_MENU";

    do{
        system("cls");
        printf("S E T T I N G S\n\n");
        create_buttons(4, settingsOptions);
        scanf("%c", &option);
        switch(option){
            case '1':
                strcpy(currentGameState, "symbols");
                break;
            
            case '2':
                strcpy(currentGameState, "firstTurn");
                break;
            
            case '3':
                strcpy(currentGameState, "menu");
                break;
        }
    }while((int)option < 49 || (int)option > 52);
}

// Game
void game(){

    bool end = false;
    int row, column;
    char winner;
    while(!end){

        system("cls");
        
        create_board(board);

        if(p1.turn == 1){
            printf("1st player turn");
            printf("\nType choosen coordinates: ");
            scanf("%d%d", &row, &column);
            while ((enter = getchar()) != '\n' && enter != EOF) {}
            
            board[row][column] = p1.symbol;
            p1.turn = 0;
            p2.turn = 1;
        }

        else if(p2.turn == 1){
            printf("2nd player turn");
            printf("\nType choosen coordinates: ");
            scanf("%d %d", &row, &column);
            while ((enter = getchar()) != '\n' && enter != EOF) {}
            board[row][column] = p2.symbol;
            p1.turn = 1;
            p2.turn = 0;
        }

        winner = check_win(board);
        if(winner){
            system("cls");
            printf("\n\nPLAYER %c HAS WON\n\n", winner);
            end = true;
        }
        
    }
}

char check_win(){

    char winner;

    for(int i = 0; i < 3; i++){
        if(board[i][1] != ' ' && board[i][1] == board[i][0] && board[i][1] == board[i][2]){
            winner = board[i][0];
            return winner;
        }
        else if(board[1][i] != ' ' && board[1][i] == board[0][i] && board[1][i] == board[2][i]){
            winner = board[i][0];
            return winner;
        }
    }
    if(board[1][1] != ' ' && ((board[1][1] == board[0][0] && board[1][1] == board[2][2]) || (board[1][1] == board[2][0] && board[1][1] == board[2][2]))){
        winner = board[1][1];
        return winner;
    }
    return 0;
}

// Visualisation
void create_board(){
    printf("  %c | %c   | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n----|-----|---");
    printf("\n  %c | %c   | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n----|-----|---");
    printf("\n  %c | %c   | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("%c\n", board[1][0]);
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
    printf("Choose: ");
}
