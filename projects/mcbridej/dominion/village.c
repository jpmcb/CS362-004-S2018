/*
John McBride
CS 362 - Software Engineering II

Description: Implementation of the adventurer card. Takes various parameters
	from the switch in cardEffect found in dominion.c
*/

#include "refactored.h"
	
int villageCard(int currentPlayer, struct gameState *state, int handPos)
{
	//+1 Card
	drawCard(currentPlayer, state);
		
	//+2 Actions - BUG ADDED: adds only 1 action
	state->numActions = state->numActions + 1;

	//discard played card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}
	