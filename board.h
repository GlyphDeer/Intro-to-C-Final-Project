#ifndef BOARD_H
#define BOARD_H

// Tells other files: "There is a board variable in board.c, go look for it there."
extern char board[3][3];
// Initialize a specific board (accepts arguments now!)
void initBoard(char board[3][3]);
// Draws the board
void drawBoard(char dBoard[3][3]);
//Clears the Screen
void clearScreen();

#endif