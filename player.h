#pragma once

#include <stdbool.h>

typedef struct
{
    char symbol;
    char occupiedWindows[10];
    unsigned int points;
    bool turn;
}Player;