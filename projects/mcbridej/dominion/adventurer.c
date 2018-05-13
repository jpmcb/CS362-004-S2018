/*
John McBride
CS 362 - Software engineerig II

Description: Implementation of the adventurer card. Takes various parameters
	from the switch in cardEffect found in dominion.c
*/ 

#include "refactored.h"

int adventurerCard(int drawntreasure, struct gameState *state, int currentPlayer, int *temphand)
{
	int z = 0;

	while(drawntreasure < 2)
	{
		if (state->deckCount[currentPlayer] < 1)
		{
			//if the deck is empty we need to shuffle discard and add to deck
	  		shuffle(currentPlayer, state);
		}
	
		drawCard(currentPlayer, state);

		//top card of hand is most recently drawn card.
		int cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
	
		// BUG ADDED: will not account for gold being drawn.
		if(cardDrawn == copper || cardDrawn == silver)
		{
	  		drawntreasure++;
		} 
		else 
		{
			temphand[z] = cardDrawn;

			//this should just remove the top card (the most recently drawn one).
			state->handCount[currentPlayer]--; 
			z++;
		}
    }
    
    while(z - 1 >= 0)
    {
    	// discard all cards in play that have been drawn
		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z-1]; 
		z = z - 1;
    }
    
    return 0;
}