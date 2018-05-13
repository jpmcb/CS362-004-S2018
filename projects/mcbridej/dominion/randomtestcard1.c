/**************
* Name: John McBride
* Date: May 13th 2018
* Description: Smithy card random tester
*       Uses utility functions found in unittesting.c
***************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "refactored.h"
#include "unittesting.h"
#include "interface.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(0));
    
    // Various variables needed to initilize loops, the game state,
    // and other testing values
    int i, j, k, randSeeding, numPlayers, game, handsize;
    int preCount, returned;

    struct gameState *state;

    // Initilize the arbitrary cards for this game
    int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel,
        smithy, village, baron, great_hall};

    // Null pointer to the hand of cards
    int *hand = 0;

    printf("Testing Smithy card!\n");
    printf("RANDOM TESTS:\n");

    // Perform random tests
    for(i = 0; i < 2000; i++)
    {
        printf("On test: %d\n", i);

        // Initilize the game
        randSeeding = randRange(1000, 1);
        numPlayers = randRange(4, 2);

        // Initlize the state struct
        state = 0;
        state = newGame();
        game = initializeGame(numPlayers, cards, randSeeding, state);

        // Initilize the players hands
        for(j = 0; j < numPlayers; j++)
        {
            // Get a random hand size and pull memory for the hand
            handsize = randRange(MAX_HAND, 0);
            hand = malloc(sizeof(int) * handsize);

            // init the hand for each player
            for(k = 0; k < handsize; k++)
            {
                // Random cards (ints cast to the enum card data type)
                hand[k] = randRange(26, 0);
            }

            // Set the had in the state struct
            memcpy(state->hand[j], hand, sizeof(int) * handsize);
            state->handCount[j] = handsize;

            free(hand);
        }

        // Perform a random test on each player with their random hand
        for(j = 0; j < numPlayers; j++)
        {
            // Set who's turn it is
            state->whoseTurn = j;

            // Check how many cards are currently in the players hand
            preCount = state->handCount[j];

            // Call the function to be tested (the smithy card - found in smithycard.c)
            returned = smithyCard(state, j, randRange(state->handCount[j], 0));

            // Check the return value:
            if(!asserttrue(0, returned)){
                printf("Case FAILED! -- Wrong return value\n");
                printf("Returned value: %d\n", returned);
                printf("number of players: %d\n", numPlayers);
                printf("failed on player: %d\n", (j + 1));
                printf("Player hand size: %d\n", state->handCount[j]);
                printf("Player hand: \n");
                printHand(j, state);
                printf("Game state: \n");
                printState(state);
            } 

            // Check the number of cards now in hand
            if(!asserttrue(preCount + 2, state->handCount[j])){
                printf("Case FAILED! -- Wrong number of cards in hand\n");
                printf("Returned value: %d\n", returned);
                printf("number of players: %d\n", numPlayers);
                printf("failed on player: %d\n", (j + 1));
                printf("Actual player hand size: %d expected: %d\n", state->handCount[j], preCount + 2);
                printf("Player hand: \n");
                printHand(j, state);
                printf("Game state: \n");
                printState(state);
            } 
        }

        free(state);
    }
}