#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "board.h"
#include "players.h"
#include "game.h"
#include "test.h"
#include "testCompleteGame.h"

//Main Global Vars
bool playAgain = true, endGame = false;
int turnTracker = 1;

//Player Pointers
Player player1, player2; 
Player *pPlayerOne = &player1;
Player *pPlayerTwo = &player2;

//Function Dec's
void playAgainLogic();
void printHeader();
void makeplayingPlayer(int playerNumber, Player *pPlayer);
void anouncePlayers(Player *pPlayerOne, Player *pPlayerTwo);
void displayCurrentBoard();
void makeCurrentMove(Player *pPlayer);
void welcomePlayer(int playerNumber);
Player *swapPlayer(Player *pPlayerOne, Player *pPlayerTwo, int turnTracker);
void initPlayers();

//Asign Player One

//Asign Player Two
//MAIN
int main () {
    Player currentPlayer, *pCurrentPlayer = &currentPlayer; //Creates a Current Player Var
    char playAgainInput;
    
    //---------------------
    //  USE FOR DEBUGGING
    //runCompleteGameTests();
    //---------------------
    
   //Init the Players
   initPlayers();
   
    //Play Again Loop
    do{
        endGame = false; //Resets Game State
        initBoard(board);
        turnTracker = 1;
        while (!endGame)
        {
            printHeader(); //Redraws the Header
            displayCurrentBoard(); //Clears board then Displays the Current Stored board with a header
            pCurrentPlayer = swapPlayer(pPlayerOne, pPlayerTwo, turnTracker); //Swaps the Palyer
            //Prompting the Current Player
            printf("              %s, it is currently your move!\n\n", pCurrentPlayer->name);
            //Making the Move
            makeCurrentMove(pCurrentPlayer);
            //Checks if we have a Winner
            endGame = determineWinner(board, pPlayerOne, pPlayerTwo);

            turnTracker++; //Increment to Next Turn
        }

    //Play Again Logic
    printf("\n");
    printf("================================================================\n");
    printf("|                WOULD YOU LIKE TO PLAY AGAIN?                 |\n");
    printf("|                   (Y) Yes   or   (N) No                      |\n");
    printf("================================================================\n");
    printf("                        Enter Choice: ");
    //Checks if the Player wants to Play Again or not
    scanf(" %c", &playAgainInput);

    } while (playAgainInput == 'y' || playAgainInput == 'Y');

    printf("\nThanks for playing! Goodbye.\n");
    return 0;
}


//Other Func's
void printHeader(){
    printf("================================================================\n");
    printf("|                   TIC  --  TAC  --  TOE                      |\n");
    printf("|                Use Coordinates (1-3) to play!                |\n");
    printf("================================================================\n");
    printf("\n");
}

void makeplayingPlayer(int playerNumber, Player *pPlayer){
    //Stores P1 Marker
    char p1Marker = pPlayerOne->symbol;
    //Takes in Name
    printf("                      What is your name? \n");
    scanf("%s", pPlayer->name); 

    if (playerNumber == 2) {
    // Logic: Assign opposite
    if(pPlayerOne->symbol == 'X' || pPlayerOne->symbol == 'x')
    {
        pPlayerTwo->symbol = 'O';
    }else{
         pPlayerTwo->symbol = 'X';
    }
    
}else{
    //Takes in maker
    bool validMarker = false;
    do{
        printf("                  Enter your marker (X or O)  \n");
        scanf(" %c", &pPlayer->symbol);
        if(checkMarker(pPlayer->symbol)) validMarker = true;
        else printf("Invalid marker! Choose X or O.\n");
        
    } while (!validMarker);
}    
}

void anouncePlayers(Player *pPlayerOne, Player *pPlayerTwo){
    //Anounces Player One
    printf("Hello Player %s, you are marker %c, and you go first!\n", pPlayerOne->name, pPlayerTwo->symbol);
    //Anounces Player Two
    printf("Hello Player %s, you are marker %c, and you go second!\n", pPlayerOne->name, pPlayerTwo->symbol);
    //Says Goodluck!
    printf("Goodluck!\n");
}

Player *swapPlayer(Player *pPlayerOne, Player *pPlayerTwo, int turnTracker){   
    //Check if Even if so returns player two
    if((turnTracker%2) != 0){
        return pPlayerOne;
    }
    //Returns Player One
    return pPlayerTwo;
}

void displayCurrentBoard(){
    clearScreen();
    printHeader();
    printf("================================================================\n");
    printf("|               Current -- TIC TAC -- TOE Board                |\n");
    printf("================================================================\n");
    printf("\n");
    printf("\n");
    printf("   Player 1: %s (%c)\n", pPlayerOne->name, pPlayerOne->symbol);
    printf("   Player 2: %s (%c)\n", pPlayerTwo->name, pPlayerTwo->symbol);
    printf("\n");
    drawBoard(board);

}

void makeCurrentMove(Player *pPlayer){
    int row = 0, col = 0;
    bool moveSuccess = false; // Flag to track if we are done

    // Loop until a valid move is successfully made
    do {
        printf("Enter a Valid Spot (row col): ");
        if(scanf("%d %d", &row, &col) != 2) {
            while(getchar() != '\n'); //Checks if they used Letters
            printf("Invalid Input! Use numbers.\n");
            continue;
        }
        //Updates Board if Valid Move
        if(makeMove(board, pPlayer, row, col) == true) {
            moveSuccess = true; // We are done, exit the loop
        }
        else {
            // makeMove already prints "Invalid Move", so we just loop again
            moveSuccess = false;
        }
    } while(!moveSuccess);
}

void welcomePlayer(int playerNumber){
if(playerNumber == 1){
    printf("================================================================\n");
    printf("|                      WELCOME PLAYER ONE                      |\n");
    printf("================================================================\n");
}else if(playerNumber == 2){
    printf("================================================================\n");
    printf("|                      WELCOME PLAYER TWO                      |\n");
    printf("================================================================\n");
}

}

void initPlayers(){
    //Used to make the Main less bulky with making the two players
    bool checkSameMarker = false;
 
    //Player One                                                 //Prints p1 header
    printf("\n                   Time To Set Your Players!\n");    //Setting Prompt
    welcomePlayer(1);                                              //welcomes p1
    makeplayingPlayer(1, pPlayerOne);                              //makes p1
    clearScreen();                                                 //Clears Player One Setting

    //Player Two
    printf("\n                   Time To Set Your Players!\n");                                                 //Prints p2 header
    welcomePlayer(2);                                              //Welcomes p2

    //Logic to check Duplicate Marker
    do{
        makeplayingPlayer(2, pPlayerTwo);
        if(pPlayerTwo->symbol != pPlayerOne->symbol) checkSameMarker = true;
    }while (!checkSameMarker);

    clearScreen(); //Clears Player Two Setting

    printHeader();
    //Anounces the Players and Says Start
    anouncePlayers(pPlayerOne,pPlayerTwo);



}
