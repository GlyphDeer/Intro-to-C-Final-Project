#ifndef PLAYERS_H //Check if We Included Players
#define PLAYERS_H
#include <stdbool.h>


//Making Player Structure
typedef struct
{
    char name[100]; //name for the player
    char symbol;  //symbol for the player
}Player;

//Function Def
//Sets Player Name to a String, by taking a player, and name
void playerName(Player *psetPlayerName, char playerName[100]);
//Sets Player Maker to Input, by taking a player, and a marker char
void playerMarker(Player *psetPlayerMarker, char playerMarker);
bool checkMarker(char playerMarker); //Checks Player Maker (Retruns true if valid)
//Debug Tool to Print a Player
void printPlayer(Player *pPlayerInfo);
//Make Player, tool used to make a player
void makePlayer(Player *pMakePlayer, char playerName[100], char playerMarker);


#endif


