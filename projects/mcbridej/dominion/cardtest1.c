/* *********************
* Name : John McBride
* Date: April 28th 2018
* Description: These unit tests check the various
*       components of the smithy card
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
    // Set up game state variables
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

    printf("\n---------\nStarting Smithy unit tests\n---------\n");

    // Set up the game state
    state = 0;
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    // set the players hands
    memcpy(state->hand[0], hand, sizeof(int) * 100);
    memcpy(state->hand[1], hand, sizeof(int) * 100);
    state->handCount[0] = 100;
    state->handCount[1] = 100;

    // Call the smithy card funtion
    returned = smithyCard(state, 0, 0);

    // -------
    // Check the return value
    // -------
    printf("\n----------\nTesting return value:\n----------\n");

    // Check return value
    if(!asserttrue(0, returned)){
        printf("FAILED: Returned value was not correct\n");
    } else {
        printf("PASSED\n");
    }

    // -------
    // Testing 3 cards drawn
    // -------
    printf("\n----------\nTesting # cards drawn:\n----------\n");

    // Check that the hand count increased
    if(!asserttrue(102, state->handCount[0])){
        printf("FAILED: Player 1 - Number of cards drawn incorrect! Expected # cards: 102 Actual: %d\n", state->handCount[0]);
    } else {
        printf("PASSED\n");
    }

    returned = smithyCard(state, 1, 0);

    if(!asserttrue(102, state->handCount[1])){
        printf("FAILED: Player 2 - Number of cards drawn incorrect! Expected # cards: 102 Actual: %d\n", state->handCount[1]);
    } else {
        printf("PASSED\n");
    }

    returned = smithyCard(state, 0, 1);

    if(!asserttrue(104, state->handCount[0])){
        printf("FAILED: Player 1 - Number of cards drawn incorrect! Expected # cards: 104 Actual: %d\n", state->handCount[0]);
    } else {
        printf("PASSED\n");
    }

    returned = smithyCard(state, 1, 1);

    if(!asserttrue(104, state->handCount[1])){
        printf("FAILED: Player 2 - Number of cards drawn incorrect! Expected # cards: 104 Actual: %d\n", state->handCount[1]);
    } else {
        printf("PASSED\n");
    }

    returned = smithyCard(state, 0, 2);

    if(!asserttrue(106, state->handCount[0])){
        printf("FAILED: Player 1 - Number of cards drawn incorrect! Expected # cards: 106 Actual: %d\n", state->handCount[0]);
    } else {
        printf("PASSED\n");
    }

    returned = smithyCard(state, 1, 2);

    if(!asserttrue(106, state->handCount[1])){
        printf("FAILED: Player 2 - Number of cards drawn incorrect! Expected # cards: 106 Actual: %d\n", state->handCount[1]);
    } else {
        printf("PASSED\n");
    }

    printf("\n");
    return 0;
}