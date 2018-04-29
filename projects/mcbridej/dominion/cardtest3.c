/* *********************
* Name : John McBride
* Date: April 28th 2018
* Description: These test check the various components of the
*       village card function
************************/ 

#include "dominion.h"
#include "dominion_helpers.h"
#include "refactored.h"
#include "unittesting.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int main() {
    // Set up the game state variables 
    int randSeeding = 1000; 
    int numPlayers = 2;
    struct gameState *state;
    int game; 
    int cards[10] = {adventurer, council_room, feast, gardens, mine, 
        remodel, smithy, village, baron, great_hall
    };
    int returned;

    // Generate a hand of 100 smithy cards
    int hand[100];
    for(int i = 0; i < 100; i++){
        hand[i] = smithy;
    }

    printf("\n---------\nStarting VILLAGE unit tests\n---------\n");

    // ---------
    // Unit Test 1
    // ---------
    printf("\nUnit test #1\n----------\n");

    // Set up the game state
    state = 0;
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    // Copy hands into the players hand
    memcpy(state->hand[0], hand, sizeof(int) * 100);
    memcpy(state->hand[1], hand, sizeof(int) * 100);
    state->handCount[0] = 100;
    state->handCount[1] = 100;
    state->numActions = 0;

    returned = villageCard(0, state, 0);

    printf("Return value: ");
    if(!asserttrue(0, returned)){
        printf(" FAILED! Returned value was not 0\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Number of cards in hand: ");
    if(!asserttrue(100, state->handCount[0])){
        printf(" FAILED! Incorrect number of cards in hand. Expected: %d Actual: %d\n", 100, state->handCount[0]);
    } else {
        printf(" PASSED!\n");
    }

    printf("Number of actions: ");
    if(!asserttrue(2, state->numActions)){
        printf(" FAILED! Incorrect number of actions! Expected: 2 Actual: %d\n", state->numActions);
    } else {
        printf(" PASSED!\n");
    }


    // ---------
    // Unit Test 2
    // ---------
    printf("\nUnit test #2\n----------\n");

    // Set up the game state
    free(state);
    state = 0;
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    // Give the player some different cards
    for(int i = 0; i < 100; i++){
        hand[i] = gold;
    }

    memcpy(state->hand[0], hand, sizeof(int) * 100);
    memcpy(state->hand[1], hand, sizeof(int) * 100);
    state->handCount[0] = 100;
    state->handCount[1] = 100;
    state->numActions = 2;

    returned = villageCard(1, state, 1);

    printf("Return value: ");
    if(!asserttrue(0, returned)){
        printf(" FAILED! Returned value was not 0\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Number of cards in hand: ");
    if(!asserttrue(100, state->handCount[0])){
        printf(" FAILED! Incorrect number of cards in hand. Expected: %d Actual: %d\n", 100, state->handCount[0]);
    } else {
        printf(" PASSED!\n");
    }

    printf("Number of actions: ");
    if(!asserttrue(4, state->numActions)){
        printf(" FAILED! Incorrect number of actions! Expected: 4 Actual: %d\n", state->numActions);
    } else {
        printf(" PASSED!\n");
    }

    printf("\n");
    return 0;
}