/* *********************
* Name : John McBride
* Date:  April 28th 2018
* Description: Unit tests for the whosTurn function 
*       found in dominion.c
************************/ 

// Who's turn unit tests

#include "dominion.h"
#include "dominion_helpers.h"
#include "unittesting.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int main() {
    // Set the game state variables
    int randSeeding = 1000;
    int numPlayers = 2;
    struct gameState *state;
    int game;
    int cards[10] = {adventurer, council_room, feast, gardens, mine, 
        remodel, smithy, village, baron, great_hall
    };
    int returned;

    state = 0;
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    // ---------
    // Check the default state of the game / player turn
    // * Should just be the first player at index zero
    // ---------

    printf("\n---------\nStarting whosTurn unit tests\n---------\n");


    printf("Testing default player turn:\n");
    returned = whoseTurn(state);
    asserttrue(returned, 0);

    // ---------
    // Change the players turn and check again
    // ---------

    state->whoseTurn = 1;

    printf("Changing player turn to 1. Testing whoseTurn:");
    returned = whoseTurn(state);
    if(!asserttrue(returned, 1)){
        printf(" FAILED\n");
    } else {
        printf(" PASSED\n");
    }

    state->whoseTurn = 11;

    printf("Changing player turn to 11. Testing whoseTurn:");
    returned = whoseTurn(state);
    if(!asserttrue(returned, 11)){
        printf(" FAILED\n");
    } else {
        printf(" PASSED\n");
    }

    state->whoseTurn = 111;

    printf("Changing player turn to 111. Testing whoseTurn:");
    returned = whoseTurn(state);
    if(!asserttrue(returned, 111)){
        printf(" FAILED\n");
    } else {
        printf(" PASSED\n");
    }

    // ---------
    // Reset testing and state environment. Test again
    // ---------
    free(state);
    state = 0;
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    printf("Testing default player turn after environment reset:");
    returned = whoseTurn(state);
    if(!asserttrue(returned, 0)){
        printf(" FAILED\n");
    } else {
        printf(" PASSED\n");
    }

    // ------
    // Check a negative number (because why not?)
    // ------
    state->whoseTurn = -123;

    printf("Changing player turn to 1. Testing whoseTurn:");
    returned = whoseTurn(state);
    if(!asserttrue(returned, -123)){
        printf(" FAILED\n");
    } else {
        printf(" PASSED\n");
    }

    printf("\n");
    return 0;
}