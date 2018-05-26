/* *********************
* Name : John McBride
* Date: April 28th 2018
* Description: Unit tests for the isGameOver function
*       found in the dominion code base
************************/ 

#include "dominion.h"
#include "dominion_helpers.h"
#include "unittesting.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int main() {
    // Game state and initilization variables
    int randSeeding = 1000; 
    int numPlayers = 2;
    struct gameState *state;
    int game; 
    int cards[10] = {adventurer, council_room, feast, gardens, mine, 
        remodel, smithy, village, baron, great_hall
    };
    int returned;

    printf("\n---------\nStarting gameOver unit tests\n---------\n");

    state = 0;
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    // --------
    // Stack of provice cards is NOT emptyu
    // --------
    state->supplyCount[province] = 1;

    returned = isGameOver(state);

    printf("Province cards not empty:");
    if(assertfalse(0, state->supplyCount[province]) &&
        asserttrue(1, state->supplyCount[province]) &&
        asserttrue(FALSE, returned)){
        printf(" PASSED\n");
    } else {
        printf(" FAILED\n");
    }

    // --------
    // Test if the stack of province cards is empty
    // --------
    state->supplyCount[province] = 0;

    returned = isGameOver(state);

    printf("Province cards empty:");
    if(assertfalse(1, state->supplyCount[province]) &&
        asserttrue(0, state->supplyCount[province]) &&
        asserttrue(TRUE, returned)) {
        printf(" PASSED\n");
    } else {
        printf(" FAILED\n");
    }

    free(state);
    state = 0;

    // --------
    // 0 supply piles are empty
    // --------
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    returned = isGameOver(state);

    printf("No game over with 0 empty piles:");
    
    int count = 0;
    for(int i = 0; i < treasure_map + 1; i ++)
    {
        if(state->supplyCount[i] == 0){
            count++;
        }
    }

    if(asserttrue(count, 0) &&
        asserttrue(FALSE, returned)) {
        printf(" PASSED\n");
    } else {
        printf(" FAILED\n");
    }

    // --------
    // 1 supply pile is empty
    // --------
    state->supplyCount[0] = 0;

    returned = isGameOver(state);

    printf("Checking with 1 empty piles:");

    count = 0;
    for(int i = 0; i < treasure_map + 1; i ++)
    {
        if(state->supplyCount[i] == 0){
            count++;
        }
    }

    if(asserttrue(count, 1) &&
        asserttrue(FALSE, returned)) {
        printf(" PASSED\n");
    } else {
        printf(" FAILED\n");
    }

    // --------
    // 2 supply piles are empty
    // --------
    state->supplyCount[1] = 0;

    returned = isGameOver(state);

    printf("Checking with 2 empty piles:");

    count = 0;
    for(int i = 0; i < treasure_map + 1; i ++)
    {
        if(state->supplyCount[i] == 0){
            count++;
        }
    }

    if(asserttrue(count, 2) &&
        asserttrue(FALSE, returned)) {
        printf(" PASSED\n");
    } else {
        printf(" FAILED\n");
    }

    // --------
    // 3 supply piles are empty (first 3 piles)
    // --------
    state->supplyCount[2] = 0;

    returned = isGameOver(state);

    printf("Checking with 3 empty piles:");

    count = 0;
    for(int i = 0; i < treasure_map + 1; i ++)
    {
        if(state->supplyCount[i] == 0){
            count++;
        }
    }

    if(asserttrue(count, 3) &&
        asserttrue(TRUE, returned)) {
        printf(" PASSED\n");
    } else {
        printf(" FAILED\n");
    }

    // --------
    // Last 3 piles are empty
    // --------
    free(state);
    state = 0; 
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    state->supplyCount[treasure_map] = 0;
    state->supplyCount[treasure_map - 1] = 0;
    state->supplyCount[treasure_map - 2] = 0;

    returned = isGameOver(state);

    printf("Checking last 3 piles empty:");

    count = 0;
    for(int i = 0; i < treasure_map + 1; i ++)
    {
        if(state->supplyCount[i] == 0){
            count++;
        }
    }

    if(asserttrue(count, 3) &&
        asserttrue(TRUE, returned)) {
        printf(" PASSED\n");
    } else {
        printf(" FAILED\n");
    }

    // -------
    // 3 random piles empty
    // -------
    free(state);
    state = 0; 
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    state->supplyCount[treasure_map] = 0;
    state->supplyCount[treasure_map - 12] = 0;
    state->supplyCount[0] = 0;

    returned = isGameOver(state);

    printf("Checking 3 random piles empty:");

    count = 0;
    for(int i = 0; i < treasure_map + 1; i ++)
    {
        if(state->supplyCount[i] == 0){
            count++;
        }
    }

    if(asserttrue(count, 3) &&
        asserttrue(TRUE, returned)) {
        printf(" PASSED\n");
    } else {
        printf(" FAILED\n");
    }

    // --------
    // All supply piles are empty
    // --------
    for(int i = 0; i < treasure_map + 1; i++){
        state->supplyCount[i] = 0;
    }

    returned = isGameOver(state);

    printf("Checking ALL piles empty:");

    count = 0;
    for(int i = 0; i < treasure_map + 1; i ++)
    {
        if(state->supplyCount[i] == 0){
            count++;
        }
    }

    if(asserttrue(count, 3) &&
        asserttrue(TRUE, returned)) {
        printf(" PASSED\n");
    } else {
        printf(" FAILED\n");
    }

    printf("\n");
    return 0;
}  