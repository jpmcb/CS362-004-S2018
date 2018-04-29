/* *********************
* Name : John McBride
* Date: April 28th 2018
* Description: These unit tests check the various components of the 
*       adventurer card
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
    // Set the various game state variables
    int randSeeding = 1000; 
    int numPlayers = 2;
    struct gameState *state;
    int game; 
    int cards[10] = {adventurer, council_room, feast, gardens, mine, 
        remodel, smithy, village, baron, great_hall
    };
    int returned;

    // Generate a hand of 4 cards
    int hand[4];
    hand[0] = smithy;
    hand[1] = adventurer;
    hand[2] = adventurer;
    hand[3] = adventurer;

    // Generate a deck of all smithy cards
    int deck[50];
    for(int i = 0; i < 50; i++){
        deck[i] = smithy;
    }

    // Set 3 deck cards to treasure cards
    deck[49] = copper;
    deck[48] = silver;
    deck[47] = gold;

    // Set up the temporary hand
    int temphand[MAX_HAND];
    for(int i = 0; i < MAX_HAND; i++){
        temphand[i] = -1;
    }

    // Treasure specific variables
    int drawntreasure = 0;

    printf("\n---------\nStarting Adventurer unit tests\n---------\n");

    // Initilize the game state
    state = 0;
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    // Set the players hands and decks
    memcpy(state->hand[0], hand, sizeof(int) * 4);
    memcpy(state->hand[1], hand, sizeof(int) * 4);
    memcpy(state->deck[0], deck, sizeof(int) * 50);
    memcpy(state->deck[1], deck, sizeof(int) * 50);
    state->handCount[0] = 4;
    state->handCount[1] = 4;
    state->deckCount[0] = 50;
    state->deckCount[1] = 50;

    // ----------
    // Unit test 1
    // ----------
    returned = adventurerCard(drawntreasure, state, 0, temphand);

    printf("\n-----------\nBeginning unit test 1: Mixed treasure deck\n-----------\n");

    // Check that the return value is valid
    printf("Return value: ");
    if(!asserttrue(0, returned)){
        printf(" FAILED! Returned value was not correct\n");
    } else {
        printf(" PASSED!\n");
    }

    // Check that hand count has increased
    printf("Hand count increased: ");
    if(!asserttrue(6, state->handCount[0])){
        printf(" FAILED! Expected hand count: %d Actual: %d\n", 6, state->handCount[0]);
    } else {
        printf(" PASSED!\n");
    }

    // Check current hand contents
    printf("Correct cards in hand: ");

    int cardCounter = 0;
    for(int i = 0; i < state->handCount[0]; i++){
        if(state->hand[0][i] == copper || state->hand[0][i] == silver || state->hand[0][i] == gold){
            cardCounter++;
        }

        if(cardCounter == 2){
            break;
        }
    }
    if(!asserttrue(cardCounter, 2)){
        printf(" FAILED! Expected # of treasure cards: %d Actual: %d\n", 2, cardCounter);
    } else {
        printf(" PASSED!\n");
    }

    // ----------
    // Unit Test 2 - Only Copper
    // ----------
    free(state);

    drawntreasure = 0;

    state = 0;
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    deck[49] = copper;
    deck[48] = copper;
    deck[47] = copper;

    memcpy(state->hand[0], hand, sizeof(int) * 4);
    memcpy(state->hand[1], hand, sizeof(int) * 4);
    memcpy(state->deck[0], deck, sizeof(int) * 50);
    memcpy(state->deck[1], deck, sizeof(int) * 50);
    state->handCount[0] = 4;
    state->handCount[1] = 4;
    state->deckCount[0] = 50;
    state->deckCount[1] = 50;

    returned = adventurerCard(drawntreasure, state, 0, temphand);

    printf("\n-----------\nBeginning unit test 2: Only copper in deck\n-----------\n");

    // Check that the return value is valid
    printf("Return value: ");
    if(!asserttrue(0, returned)){
        printf(" FAILED! Returned value was not correct\n");
    } else {
        printf(" PASSED!\n");
    }

    // Check that hand count has increased
    printf("Hand count increased: ");
    if(!asserttrue(6, state->handCount[0])){
        printf(" FAILED! Expected hand count: %d Actual: %d\n", 6, state->handCount[0]);
    } else {
        printf(" PASSED!\n");
    }

    // Check current hand contents
    printf("Correct cards in hand: ");

    cardCounter = 0;
    for(int i = 0; i < state->handCount[0]; i++){
        if(state->hand[0][i] == copper) {
            cardCounter++;
        }
    }

    if(!asserttrue(cardCounter, 2)){
        printf(" FAILED! Expected # of copper cards: %d Actual: %d\n", 2, cardCounter);
    } else {
        printf(" PASSED!\n");
    }

    // -------------
    // Unit test 3: Only silver
    // -------------

    free(state);

    drawntreasure = 0;

    state = 0;
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    deck[49] = silver;
    deck[48] = silver;
    deck[47] = silver;

    memcpy(state->hand[0], hand, sizeof(int) * 4);
    memcpy(state->hand[1], hand, sizeof(int) * 4);
    memcpy(state->deck[0], deck, sizeof(int) * 50);
    memcpy(state->deck[1], deck, sizeof(int) * 50);
    state->handCount[0] = 4;
    state->handCount[1] = 4;
    state->deckCount[0] = 50;
    state->deckCount[1] = 50;

    returned = adventurerCard(drawntreasure, state, 0, temphand);

    printf("\n-----------\nBeginning unit test 3: Only silver in deck\n-----------\n");

    // Check that the return value is valid
    printf("Return value: ");
    if(!asserttrue(0, returned)){
        printf(" FAILED! Returned value was not correct\n");
    } else {
        printf(" PASSED!\n");
    }

    // Check that hand count has increased
    printf("Hand count increased: ");
    if(!asserttrue(6, state->handCount[0])){
        printf(" FAILED! Expected hand count: %d Actual: %d\n", 6, state->handCount[0]);
    } else {
        printf(" PASSED!\n");
    }

    // Check current hand contents
    printf("Correct cards in hand: ");

    cardCounter = 0;
    for(int i = 0; i < state->handCount[0]; i++){
        if(state->hand[0][i] == silver) {
            cardCounter++;
        }
    }

    if(!asserttrue(cardCounter, 2)){
        printf(" FAILED! Expected # of silver cards: %d Actual: %d\n", 2, cardCounter);
    } else {
        printf(" PASSED!\n");
    }

    // -------------
    // Unit test 4: Only gold
    // -------------

    free(state);

    drawntreasure = 0;

    state = 0;
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    deck[49] = gold;
    deck[48] = gold;
    deck[47] = gold;

    memcpy(state->hand[0], hand, sizeof(int) * 4);
    memcpy(state->hand[1], hand, sizeof(int) * 4);
    memcpy(state->deck[0], deck, sizeof(int) * 50);
    memcpy(state->deck[1], deck, sizeof(int) * 50);
    state->handCount[0] = 4;
    state->handCount[1] = 4;
    state->deckCount[0] = 50;
    state->deckCount[1] = 50;

    returned = adventurerCard(drawntreasure, state, 0, temphand);

    printf("\n-----------\nBeginning unit test 4: Only gold in deck\n-----------\n");

    // Check that the return value is valid
    printf("Return value: ");
    if(!asserttrue(0, returned)){
        printf(" FAILED! Returned value was not correct\n");
    } else {
        printf(" PASSED!\n");
    }

    // Check that hand count has increased
    printf("Hand count increased: ");
    if(!asserttrue(6, state->handCount[0])){
        printf(" FAILED! Expected hand count: %d Actual: %d\n", 6, state->handCount[0]);
    } else {
        printf(" PASSED!\n");
    }

    // Check current hand contents
    printf("Correct cards in hand: ");

    cardCounter = 0;
    for(int i = 0; i < state->handCount[0]; i++){
        if(state->hand[0][i] == gold) {
            cardCounter++;
        }
    }

    if(!asserttrue(cardCounter, 2)){
        printf(" FAILED! Expected # of gold cards: %d Actual: %d\n", 2, cardCounter);
    } else {
        printf(" PASSED!\n");
    }

    printf("\n");
    return 0;
}