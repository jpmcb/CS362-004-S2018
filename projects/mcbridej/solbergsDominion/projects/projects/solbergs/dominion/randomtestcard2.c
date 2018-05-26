/**************
* Name: John McBride
* Date: May 13th 2018
* Description: Village card random tester
***************/

#include "dominion.h"
#include "dominion_helpers.h"
// #include "refactored.h"
#include "unittesting.h"
#include "interface.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(0));

    // Initilize variables for testing, setting up the game, and
    // for various loop counters
    int i, j, k, randSeeding, numPlayers, game, handsize;
    int preCount, preActions, returned;

    struct gameState *state;

    // Initilize arbitray cards for the testing suit to use
    int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel,
        smithy, village, baron, great_hall};

    // Empty pointer for the cards each player will hold
    int *hand = 0;

    printf("Testing village card!\n");
    printf("RANDOM TESTS:\n");

    // Perform the random tests
    for(i = 0; i < 2000; i++)
    {
        printf("On test: %d\n", i);

        // Generate the game state variables
        randSeeding = randRange(1000, 1);
        numPlayers = randRange(4, 2);

        // Initilize the game state struct
        state = 0;
        state = newGame();
        game = initializeGame(numPlayers, cards, randSeeding, state);

        // Generate the hands for each player
        for(j = 0; j < numPlayers; j++)
        {
            // Get a random hand size and allocate memory for it
            handsize = randRange(MAX_HAND, 0);
            hand = malloc(sizeof(int) * handsize);

            // init the hand for each player
            for(k = 0; k < handsize; k++)
            {
                // Random card in each position (int casts to the enum data type)
                hand[k] = randRange(26, 0);
            }

            // copy over the players hand into the state structure
            memcpy(state->hand[j], hand, sizeof(int) * handsize);
            state->handCount[j] = handsize;

            // Clean up the hand memory for next round
            free(hand);
        }

        // Perform the random tests for each 
        for(j = 0; j < numPlayers; j++)
        {
            // Set the state variables for this test
            state->whoseTurn = j;
            state->numActions = 0;

            // track the number of actions and the hand count for the player
            preCount = state->handCount[j];
            preActions = state->numActions;

            // test the village function (can be found for the village card in villagecard.c)
            returned = playVillage(j, state, randRange(state->handCount[j], 0));

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
            if(!asserttrue(preCount, state->handCount[j])){
                printf("Case FAILED! -- Wrong number of cards in hand\n");
                printf("Returned value: %d\n", returned);
                printf("number of players: %d\n", numPlayers);
                printf("failed on player: %d\n", (j + 1));
                printf("Actual player hand size: %d expected: %d\n", state->handCount[j], preCount + 1);
                printf("Player hand: \n");
                printHand(j, state);
                printf("Game state: \n");
                printState(state);
            } 

            // Check the number of actions for the player now
            if(!asserttrue(preActions + 2, state->numActions)){
                printf("Case FAILED! -- Wrong number of actions\n");
                printf("Returned value: %d\n", returned);
                printf("number of players: %d\n", numPlayers);
                printf("failed on player: %d\n", (j + 1));
                printf("Expected actions: 2 Actual actions: %d", state->numActions);
                printf("Game state: \n");
                printState(state);
            } 
        }

        // Clean up the state for next round
        free(state);
    }
}