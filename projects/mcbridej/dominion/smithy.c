/*
John McBride
CS 362 - Software Engineering II

Description: Implementation of the smithy card. Takes various parameters
	from the switch in cardEffect found in dominion.c
*/

#include "refactored.h"

int smithyCard(struct gameState *state, int currentPlayer, int handPos)
{
	//+3 Cards -- BUG ADDED: i initilized to 1 (should be 0)
  	for (int i = 1; i < 3; i++)
	{
  		drawCard(currentPlayer, state);
	}
		
  	//discard card from hand
  	discardCard(handPos, currentPlayer, state, 0);
  	return 0;
}