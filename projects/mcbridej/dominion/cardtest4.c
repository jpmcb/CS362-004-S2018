/* *********************
* Name : John McBride
* Date: April 28th 2018
* Description: This unit test checks the various components
*       of the garden card in the dominion code base.
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
    // Set up the game variables
    int randSeeding = 1000; 
    int numPlayers = 2;
    struct gameState *state;
    int game; 
    int cards[10] = {adventurer, council_room, feast, gardens, mine, 
        remodel, smithy, village, baron, great_hall
    };
    int returned;

    printf("\n---------\nStarting Gardens unit tests\n---------\n");

    // ---------
    // Unit Test 1
    // ---------

    // Set up the game state
    state = 0;
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    // Call the garden card function
    returned = gardensCard();

    // Check the return value of the 
    printf("Return value: ");
    if(!asserttrue(-1, returned)){
        printf(" FAILED! Returned value was not -1\n");
    } else {
        printf(" PASSED!\n");
    }

    // ---------
    // Unit Test 2
    // ---------

    // clean up previous state & reinitilize
    free(state);
    state = 0;
    numPlayers = 4;
    randSeeding = 5000;
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    // Call the garden card function
    returned = gardensCard();

    // Check the return value
    printf("Return value: ");
    if(!asserttrue(-1, returned)){
        printf(" FAILED! Returned value was not -1\n");
    } else {
        printf(" PASSED!\n");
    }

    // ---------
    // Unit Test 3
    // ---------

    // Clean up previous state & reinitilize
    free(state);
    state = 0;
    numPlayers = 5;
    randSeeding = 1;
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    // Call garden card function
    returned = gardensCard();

    // Check the return value
    printf("Return value: ");
    if(!asserttrue(-1, returned)){
        printf(" FAILED! Returned value was not -1\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("\n");
    return 0;
}
