/* *********************
* Name : John McBride
* Date:  April 28th 2018
* Description: This file will perform several unit tests on the 
*       discard function in the dominion code base. Several assumptions
*       are made regarding how the "Played" cards are handled and how
*       the trash pile works regarding the overal game structure. 
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
    // Set the variables needed to initilize the game and the game state
    int randSeeding = 1234;
    int handPos;
    int currentPlayer = 0;
    int numPlayers = 2;
    struct gameState *state;
    int trashFlag;
    int game;
    int cards[10] = {adventurer, council_room, feast, gardens, mine, 
        remodel, smithy, village, baron, great_hall
    };

    printf("\n---------\nStarting discardCard unit tests\n---------\n");

    // Create a max hand of copper cards
    int hand[MAX_HAND];
    for(int i = 0; i < MAX_HAND; i++){
        hand[i] = copper;
    }

    // --------
    // Basic Unit test #1:
    //  * Trash flag is on (card should be placed in "played" pile)
    //  * Large hand of cards for both players. 
    //  # Check that the various game state variables are appropriate
    // --------
    trashFlag = TRUE;

    // Set up the game state
    state = 0;
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    // Get the hands into the state struct for both players & set the count
    memcpy(state->hand[0], hand, sizeof(int) * MAX_HAND);
    memcpy(state->hand[1], hand, sizeof(int) * MAX_HAND);
    state->handCount[0] = MAX_HAND;
    state->handCount[1] = MAX_HAND;

    // Loop for each player
    for(currentPlayer = 0; currentPlayer < numPlayers; currentPlayer++){

        // Loop for each card in the players hand
        for(handPos = 0; handPos < MAX_HAND; handPos++){
            // Original state values
            int previousCount = state->playedCardCount;
            int playedCard = state->hand[currentPlayer][handPos];

            // Call the function in dominion.c
            discardCard(handPos, currentPlayer, state, trashFlag);

            // Check if the hand count is correct
            if (!asserttrue((MAX_HAND - 1 - handPos), state->handCount[currentPlayer])){
                printf("FAILED TEST: Expected hand count: %d Actual count: %d \n", (MAX_HAND - 1 - handPos), state->handCount[currentPlayer]);
            }
            
            // Check if the played card count is correct.
            // With the trash flag set to , should NOT increment 
            if (!asserttrue(previousCount, state->playedCardCount)){
                 printf("FAILED TEST: Expected played Card count: %d Actual count: %d \n", (previousCount + 1), state->playedCardCount);
            }
            
            // Check if the played card is NOT in the trash pile
            if (!assertfalse(playedCard, state->playedCards[(state->playedCardCount - 1)])){
                printf("FAILED TEST: Card NOT in 'Played' pile - currentPlayer: %d handPos: %d \n", currentPlayer, handPos);
            }

            // Check if the last card "in hand" is now -1 
            if (!asserttrue(-1, state->hand[currentPlayer][state->handCount[currentPlayer]])){
                printf("FAILED TEST: Last card in hand NOT -1 - currentPlayer: %d handPos: %d \n", currentPlayer, handPos);

            }
        }
    }

    // Clean up!
    free(state);
    state = 0;

    // ---------
    // Basic unit test #2
    // * Trash flag is off, card should not be in played pile
    // * Check if the last card in the hand is appropriatly now -1 
    // * Check the game state variables
    // ---------

    // Set up the appropriate variables for the new testing 
    trashFlag = FALSE;

    // Reset the game state
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    // Reset the cards in each players hand
    memcpy(state->hand[0], hand, sizeof(int) * MAX_HAND);
    memcpy(state->hand[1], hand, sizeof(int) * MAX_HAND);
    state->handCount[0] = MAX_HAND;
    state->handCount[1] = MAX_HAND;

    for(currentPlayer = 0; currentPlayer < numPlayers; currentPlayer++){
        for(handPos = 0; handPos < MAX_HAND; handPos++){
            // Original state values
            int previousCount = state->playedCardCount;
            int playedCard = state->hand[currentPlayer][handPos];

            discardCard(handPos, currentPlayer, state, trashFlag);

            // Check if the hand count is correct
            if (!asserttrue((MAX_HAND - 1 - handPos), state->handCount[currentPlayer])){
                printf("FAILED TEST: Expected hand count: %d Actual count: %d \n", (MAX_HAND - 1 - handPos), state->handCount[currentPlayer]);
            }
            
            // Check if the played card count is correct.
            // With the trash flag set off, should increment 
            if (!asserttrue(previousCount + 1, state->playedCardCount)){
                 printf("FAILED TEST: Expected played Card count: %d Actual count: %d \n", (previousCount + 1), state->playedCardCount);
            }
            
            // Check if the played card is correctly in the played pile
            if (!asserttrue(playedCard, state->playedCards[(state->playedCardCount - 1)])){
                printf("FAILED TEST: Card NOT in 'Played' pile - currentPlayer: %d handPos: %d \n", currentPlayer, handPos);
            }

            // Check if the last card "in hand" is now -1 
            if (!asserttrue(-1, state->hand[currentPlayer][state->handCount[currentPlayer]])){
                printf("FAILED TEST: Last card in hand NOT -1 - currentPlayer: %d handPos: %d \n", currentPlayer, handPos);

            }
        }
    }

    // Clean up!
    free(state);
    state = 0;

    // ---------
    // Only one card in hand to play.
    // * Use only one card in hand
    // * Check to ensure proper numbers still working
    // ---------

    // Set variables
    trashFlag = FALSE;
    currentPlayer = 0;
    handPos = 0;

    // Reset the game state
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    // Create a new hand with only one card
    int newHand[] = {4};

    for(int i = 0; i < 300; i++){

        // Reset the player hand
        memcpy(state->hand[0], newHand, sizeof(int) * 1);
        memcpy(state->hand[1], newHand, sizeof(int) * 1);
        state->handCount[0] = 1;
        state->handCount[1] = 1;

        // Old state values
        int previousCount = state->playedCardCount;
        int playedCard = state->hand[currentPlayer][handPos];

        discardCard(handPos, currentPlayer, state, trashFlag);

        // Check if the hand count is correct
        if (!asserttrue(0, state->handCount[currentPlayer])){
            printf("FAILED TEST: Expected hand count: %d Actual count: %d \n", 0, state->handCount[currentPlayer]);
        }
        
        // Check if the played card count is correct.
        // With the trash flag set off, should increment 
        if (!asserttrue(previousCount + 1, state->playedCardCount)){
             printf("FAILED TEST: Expected played Card count: %d Actual count: %d \n", (previousCount + 1), state->playedCardCount);
        }
        
        // Check if the played card is correctly in the played pile
        if (!asserttrue(playedCard, state->playedCards[(state->playedCardCount - 1)])){
            printf("FAILED TEST: Card NOT in 'Played' pile - currentPlayer: %d handPos: %d \n", currentPlayer, handPos);
        }

        // Check if the last card "in hand" is now -1 
        if (!asserttrue(-1, state->hand[currentPlayer][state->handCount[currentPlayer]])){
            printf("FAILED TEST: Last card in hand NOT -1 - currentPlayer: %d handPos: %d \n", currentPlayer, handPos);

        }
    }

    // Clean up!
    free(state);
    state = 0;

    printf("\n");
    return 0;
}