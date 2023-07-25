#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "visualisation.h"
#include "player.h"
#include "game.h"

// TODO:
/*
2. settings, saves etc.
3. Analyze game
4. Points and loading it
*/

// Navigating through game
char option = -1;
char currentGameState[9] = "menu";

// Collecting trash
char enter;

// Initializing board to play
char board[3][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '}};

// Initializing players
Player p1 = {'X', "", 0, 1};
Player p2 = {'O', "", 0, 0};


// All related to the menu
void menu();

// All related to the settings
void settings();

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
            game(p1, p2, board, option, currentGameState);
        }

        else if(strcmp(currentGameState, "load") == 0){
            return 0;
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
        create_buttons(3, settingsOptions);
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
