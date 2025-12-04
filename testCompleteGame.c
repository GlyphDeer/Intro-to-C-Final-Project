#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "board.h"
#include "game.h"
#include "players.h"
#include "testCompleteGame.h"

// Helper to print results
void assertTest(char *testName, bool condition) {
    if (condition) {
        printf("[PASS] %s\n", testName);
    } else {
        printf("[FAIL] %s\n", testName);
    }
}

// TEST 1: The "Sanity" Check
// Does placing a piece at (1, 2) actually put it at board[0][1]?
void testCoordinateConsistency() {
    char board[3][3];
    initBoard(board);
    Player p = {"TestPlayer", 'X'};

    // We ask to place at Row 1, Col 2.
    // In Array terms (0-indexed), this should be board[0][1].
    makeMove(board, &p, 1, 2);

    // DIRECTLY check the array memory. 
    // If your logic is swapped (board[col][row]), this test will fail.
    bool isAtCorrectSpot = (board[0][1] == 'X');
    bool isAtSwappedSpot = (board[1][0] == 'X');

    if (isAtCorrectSpot && !isAtSwappedSpot) {
        assertTest("Coordinate Consistency (Row 1, Col 2 goes to [0][1])", true);
    } else if (isAtSwappedSpot) {
        printf("[FAIL] Coordinate Consistency: You placed X at [1][0] instead of [0][1]. Your rows/cols are swapped!\n");
    } else {
        assertTest("Coordinate Consistency", false);
    }
}

// TEST 2: Row Win Simulation
// X X X
// . . .
// . . .
void cgTestRowWin() {
    char board[3][3];
    initBoard(board);
    Player p1 = {"P1", 'X'};
    
    // Manually set a Row Win
    // Note: We use makeMove to ensure we test the function, not just the array
    makeMove(board, &p1, 1, 1); // [0][0]
    makeMove(board, &p1, 1, 2); // [0][1]
    makeMove(board, &p1, 1, 3); // [0][2]

    assertTest("Detect Row 1 Win", checkWinner(board, &p1));
}

// TEST 3: Column Win Simulation
// O . .
// O . .
// O . .
void cgTestColWin() {
    char board[3][3];
    initBoard(board);
    Player p1 = {"P2", 'O'};
    
    makeMove(board, &p1, 1, 1); // [0][0]
    makeMove(board, &p1, 2, 1); // [1][0]
    makeMove(board, &p1, 3, 1); // [2][0]

    assertTest("Detect Column 1 Win", checkWinner(board, &p1));
}

// TEST 4: Draw Game
// X O X
// X O X
// O X O
void testDrawGame() {
    char board[3][3];
    initBoard(board);
    Player p1 = {"P1", 'X'};
    Player p2 = {"P2", 'O'};

    // Fill board without a winner
    board[0][0] = 'X'; board[0][1] = 'O'; board[0][2] = 'X';
    board[1][0] = 'X'; board[1][1] = 'O'; board[1][2] = 'X';
    board[2][0] = 'O'; board[2][1] = 'X'; board[2][2] = 'O';

    bool isDraw = checkDraw(board, &p1, &p2);
    bool isWin1 = checkWinner(board, &p1);
    bool isWin2 = checkWinner(board, &p2);

    assertTest("Detect Draw Condition", isDraw && !isWin1 && !isWin2);
}

// TEST 5: Out of Bounds Protection
void testInvalidMoves() {
    char board[3][3];
    initBoard(board);
    Player p = {"BadActor", 'X'};

    bool move1 = makeMove(board, &p, 0, 0); // Too low (1-3 is valid)
    bool move2 = makeMove(board, &p, 4, 1); // Too high
    bool move3 = makeMove(board, &p, 1, 1); // Valid
    bool move4 = makeMove(board, &p, 1, 1); // Valid but Taken

    assertTest("Reject Input 0,0", !move1);
    assertTest("Reject Input 4,1", !move2);
    assertTest("Accept Input 1,1", move3);
    assertTest("Reject Occupied Spot", !move4);
}

void runCompleteGameTests() {
    printf("\n=== RUNNING COMPLETE GAME DIAGNOSTICS ===\n");
    testCoordinateConsistency();
    cgTestRowWin();
    cgTestColWin();
    testDrawGame();
    testInvalidMoves();
    printf("=== DIAGNOSTICS COMPLETE ===\n\n");
}