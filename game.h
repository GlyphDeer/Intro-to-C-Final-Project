//Game Func Headers
#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "players.h"

//Cotains the Logic making a move
bool makeMove(char board[3][3],Player *pPlayer, int row, int col);
//Checks if a move is valid 
bool validMove(int row, int col);
//Provides all the logic for checking a winner retruns 1 if there is a win
bool checkWinner(char board[3][3], Player *pcheckPlayer);
//Checks the Board for a Player marker returns one if True;
bool boardLocationChecker(char board[3][3], int row, int col, char symbol);
//Checks if there is a draw, takes a board and two playrs
bool checkDraw(char board[3][3], Player *pPlayerOne, Player *pPlayerTwo);
//Checks if the board is full if so, retruns true
bool isBoardFull(char board[3][3]);
//Determines a winner, if so handles output
bool determineWinner(char board[3][3], Player *pPlayerOne, Player *pPlayerTwo);

#endif