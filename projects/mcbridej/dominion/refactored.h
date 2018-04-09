/*
John McBride
CS 362 - Software Engineering II

Description: Header file for the 5 refactored cards implemented in the 
	various .c files. 
*/

#ifndef REFACTORED_HPP
#define REFACTORED_HPP

#include "dominion_helpers.h"
#include <stdio.h>

int smithyCard(struct gameState *state, int currentPlayer, int handPos);
int adventurerCard(int drawntreasure, struct gameState *state, int currentPlayer, int *tempHand);
int villageCard(int currentPlayer, struct gameState *state, int handPos);
int treasure_mapCard(int index, struct gameState *state, int currentPlayer, int handPos);
int gardensCard();

#endif