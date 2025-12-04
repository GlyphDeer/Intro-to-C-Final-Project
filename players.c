#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "players.h"

//Sets the Player Name
void setplayerName(Player *psetPlayerName, char playerName[100]){
   strcpy(psetPlayerName->name, playerName);
}

//Sets the Player Marker
void setplayerMarker(Player *psetPlayerMarker, char playerMarker){
    psetPlayerMarker->symbol = playerMarker;

}

//Sets Checks if the Marker is X or O, retrun True if valid
bool checkMarker(char playerMarker){
   if(playerMarker == 'X' || playerMarker == 'x' || playerMarker == 'O' || playerMarker == 'o')
   {
    return true;
   }else
    return false;
}

//Debuging tool for Printing a Player, takes the adress of a player
void printPlayer(Player *pPlayerInfo){
    //Prints the Players Name
    printf("The player's name is %s", pPlayerInfo->name);
    //Prints the Players Marker
    printf(" their marker is %c\n", pPlayerInfo->symbol);
}

//Make Player, tool used to make a player
void makePlayer(Player *pMakePlayer, char playerName[100], char playerMarker){
    if (checkMarker(pMakePlayer->symbol) == true) 
    {
        setplayerName(pMakePlayer,playerName);
        setplayerMarker(pMakePlayer, playerMarker);
    }
    else
        printf("Invalid Player Config\n");
    
}

