#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "board.h"
#include "game.h"
#include "players.h"
#include "test.h"

void printResult(char *testName, bool passed) {
    if (passed) printf("[PASS] %s\n", testName);
    else printf("[FAIL] %s\n", testName);
}

void testRawWin() {
    char board[3][3];
    Player p = {"Tester", 'X'};
    initBoard(board);
    board[0][0] = 'X'; board[0][1] = 'X'; board[0][2] = 'X';
    printResult("Row 0 Win Detection", checkWinner(board, &p));
}

void testColWin() {
    char board[3][3];
    Player p = {"Tester", 'O'};
    initBoard(board);
    board[0][1] = 'O'; board[1][1] = 'O'; board[2][1] = 'O';
    printResult("Column 1 Win Detection", checkWinner(board, &p));
}

void testDiagWin() {
    char board[3][3];
    Player p = {"Tester", 'X'};
    initBoard(board);
    board[0][0] = 'X'; board[1][1] = 'X'; board[2][2] = 'X';
    printResult("Diagonal Win Detection", checkWinner(board, &p));
}

void testFalsePositive() {
    char board[3][3];
    Player p = {"Tester", 'X'};
    initBoard(board);
    board[0][0] = 'X'; board[0][1] = 'X'; board[0][2] = 'O'; 
    printResult("False Positive Check", checkWinner(board, &p) == false);
}

void testBoardHelpers() {
    char board[3][3];
    initBoard(board);
    board[1][1] = 'X';
    bool result = boardLocationChecker(board, 1, 1, 'X'); 
    printResult("Board Location Checker", result == true);
}

void testPlayerLogic() {
    printResult("Valid Marker X", checkMarker('X') == true);
    printResult("Invalid Marker Q", checkMarker('Q') == false);
}

void runAllTests() {
    printf("--- STARTING TESTS ---\n");
    testRawWin();
    testColWin();
    testDiagWin();
    testFalsePositive();
    testBoardHelpers();
    testPlayerLogic();
    printf("--- END TESTS ---\n");
}