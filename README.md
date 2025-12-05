Command-Line Tic-Tac-Toe (C Final Project)

Project Overview
This is a fully functional, two-player Tic-Tac-Toe game running in the command-line interface (CLI). It was developed as a final project for EGN 3211 to demonstrate what we learned  in C programming over the semseter, including:

Modular Architecture: Code separated into logic, data, and interface modules.

Memory Management: Usage of pointers and structures (struct).

Game Logic: Algorithms for win detection, draw conditions, and input validation.

Automated Testing: Integrated diagnostic suites to verify logic integrity.

Features

Dynamic Board Rendering: The board updates in real-time after every move.

Custom Player Setup: Players can enter their names and choose their markers ('X' or 'O').

Smart Input Validation: Prevents overwriting occupied spots and handles invalid data types.

Win/Draw Detection: Automatically detects rows, columns, diagonals, and stalemates.

Replay System: Allows users to play multiple rounds without restarting the program.

Diagnostic Mode: Includes a full suite of automated tests.

File Structure

The project is organized into the following modules:

main.c: The entry point. Handles the game loop, player initialization, and replay logic.

board.c / board.h: Manages the visual grid and memory initialization of the board array.

game.c / game.h: Contains core logic (win checking, move validation, draw detection).

players.c / players.h: Defines the Player structure and manages player creation.

test.c / test.h: Contains unit tests for individual functions.

testCompleteGame.c / testCompleteGame.h: Contains comprehensive scenario tests (simulated games).

Makefile: Automation script for compiling the project.

Compilation Instructions

You can compile the project using the included Makefile or manually via the terminal.

Option 1: Using Make (Recommended)

Open your terminal in the project folder.

Run the command:

make


This will generate an executable named tictactoe.

Option 2: Manual Compilation

If you do not have make installed, you can compile everything manually using clang or gcc:

clang main.c board.c game.c players.c test.c testCompleteGame.c -o tictactoe


How to Play

Run the Game:

./tictactoe


Setup:

Enter Player 1's Name.

Choose Player 1's Marker ('X' or 'O').

Enter Player 2's Name (Marker is automatically assigned).

Gameplay:

The board uses a 1-based coordinate system.

When prompted, enter the Row number and then the Column number separated by a space.

Example: To place a marker in the top-right corner, type: 1 3

Game Over:

The game ends when a player aligns 3 markers or the board is full.

Type y to play again or n to quit.

Testing & Diagnostics

The project includes a built-in testing suite to verify that the game logic is working correctly before play begins.

To enable the tests:

Open main.c.

Uncomment the line inside the main function:

// runCompleteGameTests();


Recompile and run the program.

You will see output indicating [PASS] or [FAIL] for scenarios like:

Coordinate Consistency (Row 1, Col 2 mapping to [0][1])

Row/Column/Diagonal Win Detection

Draw Condition Detection

Invalid Input Rejection

Authors

Andrew Riiska

Course: EGN 3211 - Intro to C

Date: December 4, 2025