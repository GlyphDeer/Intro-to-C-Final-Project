#include <stdio.h>
#include <stdbool.h>
#include "players.h"
#include "board.h"
#include "game.h"

//Checks the Board for a Player marker returns one if True
bool boardLocationChecker(char board[3][3], int row, int col, char symbol)
{
    if(board[row][col] == symbol) 
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Checks if the board is full if so, retruns true
// In game.c

bool isBoardFull(char board[3][3]) {
    // Loop through every spot on the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            
            // If we find even ONE empty space, the board is NOT full.
            if (board[i][j] == ' ') {
                return false; 
            }
        }
    }
    
    // If we checked every single spot and didn't find any spaces,
    // THEN the board is full.
    return true;
}

//Checks if a move is valid returns true if vailid
bool validMove(int row, int col)
{
    if(row != 0 && col !=0)
    {
        if(row <= 3 && col <= 3)
        {
            return true;
        }
    }
    return false;
}

//Defines the Logic for Being able to make a move
// In game.c

bool makeMove(char board[3][3], Player *pPlayer, int row, int col)
{
    //Check if the move numbers are within range (1-3)
    if (validMove(row, col) == true)
    {
        //Convert values to array indices (0-2)
        int r = row - 1; 
        int c = col - 1;

        // Check if the spot is empty using the corrected indexes
        if (board[r][c] == ' ')
        {
            board[r][c] = pPlayer->symbol;
            return true;
        }
    }
    
    return false;
}

//Check Winner, retruns true if they won
bool checkWinner(char board[3][3], Player *pcheckPlayer)
{
    int scoreKeeper = 0;

 // 1. Check Rows
    for(int row = 0; row < 3; row++) 
    {
        scoreKeeper = 0; // RESET SCORE FOR NEW ROW
        for(int col = 0; col < 3; col++) {
            if(boardLocationChecker(board, row, col, pcheckPlayer->symbol)) {
                scoreKeeper++;
            }
        }
        if(scoreKeeper == 3) return true;
    }

    // 2. Check Columns
    for(int col = 0; col < 3; col++)
    {
        scoreKeeper = 0; // RESET SCORE FOR NEW COL
        for(int row = 0; row < 3; row++) 
        {
            if(boardLocationChecker(board, row, col, pcheckPlayer->symbol)) 
            {
                scoreKeeper++;
            }
        }
        if(scoreKeeper == 3)
            return true;
    }

            //Checks Diag 00,11,22
    if(board[0][0] == pcheckPlayer->symbol && board[1][1] == pcheckPlayer->symbol && board[2][2] == pcheckPlayer->symbol)
    {
        return true;
    }

            //Checks Diag 20, 11, 02
    if(board[2][0] == pcheckPlayer->symbol && board[1][1] == pcheckPlayer->symbol && board[0][2] == pcheckPlayer->symbol){
            return true;
    }

    return false;
}

//Checks if there is a draw aka no winner
bool checkDraw(char board[3][3], Player *pPlayerOne, Player *pPlayerTwo)
{
    //Checks if board full, check Player One Winner, Checks Player Two Winner, if no winner retruns true
    if(isBoardFull(board) == true)
    {
        if(checkWinner(board, pPlayerOne) == true)
            return false;
        else if(checkWinner(board, pPlayerTwo) == true)
            return false;
        else
            return true;
    }
    else
        return false;
}

//Checks who won, by using checkWinner, if no winner, calls checkDraw
// In game.c

bool determineWinner(char board[3][3], Player *pPlayerOne, Player *pPlayerTwo){
    clearScreen();
    // 1. Check Player One Win
    if(checkWinner(board, pPlayerOne) == true){
        printf("\n");
        printf("================================================================\n");
        printf("|                       PLAYER ONE WINS!                       |\n");
        printf("================================================================\n");
        drawBoard(board);
        printf("                   Congratulations %s!\n", pPlayerOne->name);
        return true; 
    }
    
    // 2. Check Player Two Win
    else if(checkWinner(board, pPlayerTwo) == true){
        printf("\n");
        printf("================================================================\n");
        printf("|                       PLAYER TWO WINS!                       |\n");
        printf("================================================================\n");
        drawBoard(board);
        printf("                   Congratulations %s!\n", pPlayerTwo->name);
        return true; 
    }
    
    // 3. Check for Draw
    else if(checkDraw(board, pPlayerOne, pPlayerTwo) == true){
        printf("\n");
        printf("================================================================\n");
        printf("|                         IT'S A DRAW!                         |\n");
        printf("================================================================\n");
        return true; 
    }

    return false;
}





