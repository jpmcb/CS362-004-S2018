/*
John McBride
CS 362 - Software Engineering II

Description: Implementation of the treasure map card. Takes various parameters
	from the switch in cardEffect found in dominion.c
*/

#include "refactored.h"

int treasure_mapCard(int index, struct gameState *state, int currentPlayer, int handPos)
{
	//search hand for another treasure_map
	index = -1;
	for (int i = 0; i < state->handCount[currentPlayer]; i++)
	{
		if (state->hand[currentPlayer][i] == treasure_map && i != handPos)
		{
	  		index = i;
	  		break;
		}
	}

	if (index > -1)
	{
		//trash both treasure cards
		discardCard(handPos, currentPlayer, state, 1);
		discardCard(index, currentPlayer, state, 1);

		//gain 4 Gold cards - BUG ADDED: gives 6 gold
		for (int i = 0; i < 6; i++)
		{
	  		gainCard(gold, state, 1, currentPlayer);
		}
			
		//return success
		return 1;
	}
		
	//no second treasure_map found in hand
	return -1;
}