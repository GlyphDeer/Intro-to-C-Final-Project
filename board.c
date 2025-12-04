#include <stdio.h>
#include "board.h"

// Defines the global game board
char board[3][3];

//Prints the Board
// In board.c

void drawBoard(char board[3][3])
{
    printf("\n");
    // 1. Print Column Numbers (centered over the columns)
    printf("                           1   2   3\n"); 

    // 2. Top Border
    printf("                         +---+---+---+\n");
    
    // 3. Row 1
    printf("                       1 | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
    printf("                         +---+---+---+\n");
    
    // 4. Row 2
    printf("                       2 | %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
    printf("                         +---+---+---+\n");
    
    // 5. Row 3
    printf("                       3 | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
    printf("                         +---+---+---+\n");
    printf("\n");
}

//Fills the Board with Test Values
void fillWithTrash()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '*';
        }
    }
    
}

//Fills the Board with Blank Values
void initBoard(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void clearScreen()
{
    // \033[H moves the cursor to the top left
    // \033[J clears the screen from the cursor down
    printf("\033[H\033[J");
}