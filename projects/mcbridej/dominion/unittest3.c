/* *********************
* Name : John McBride
* Date: 
* Description: Unit tests for the supply Count function 
*       found in the dominion code base
************************/ 

// testing supplyCount

#include "dominion.h"
#include "dominion_helpers.h"
#include "unittesting.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int main() {
    // Game state variables
    int randSeeding = 2000;
    int numPlayers = 2;
    int card;
    int check;
    struct gameState *state; 
    int game;
    int cards[10] = {adventurer, council_room, feast, gardens, mine, 
        remodel, smithy, village, baron, great_hall
    };

    state = 0;
    state = newGame();
    game = initializeGame(numPlayers, cards, randSeeding, state);

    // ---------------------
    // Unit Test 1: 
    // Test each return value from what is set for each card
    // ---------------------

    printf("\n---------\nStarting supplyCount unit tests\n---------\n");


    printf("Testing Curse:");
    card = curse;
    state->supplyCount[card] = 10;
    check = state->supplyCount[card];
    if(!asserttrue(check, 10)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }
    
    printf("Testing estate:");
    card = estate;
    state->supplyCount[card] = 0;
    check = state->supplyCount[card];
    if(!asserttrue(check, 0)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }
    
    printf("Testing Duchy:");
    card = duchy;
    state->supplyCount[card] = 1000;
    check = state->supplyCount[card];
    if(!asserttrue(check, 1000)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }
    
    printf("Testing Province:");
    card = province;
    state->supplyCount[card] = 1;
    check = state->supplyCount[card];
    if(!asserttrue(check, 1)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing Copper:");
    card = copper;
    state->supplyCount[card] = 214000000;
    check = state->supplyCount[card];
    if(!asserttrue(check, 214000000)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }
   
    printf("Testing Silver:");
    card = silver;
    state->supplyCount[card] = -1;
    check = state->supplyCount[card];
    if(!asserttrue(check, -1)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing Gold:");
    card = gold;
    state->supplyCount[card] = 999;
    check = state->supplyCount[card];
    if(!asserttrue(check, 999)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing Adventurer:");
    card = adventurer;
    state->supplyCount[card] = 1234;
    check = state->supplyCount[card];
    if(!asserttrue(check, 1234)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing council room:");
    card = council_room;
    state->supplyCount[card] = 2345;
    check = state->supplyCount[card];
    if(!asserttrue(check, 2345)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing feast:");
    card = feast;
    state->supplyCount[card] = 3456;
    check = state->supplyCount[card];
    if(!asserttrue(check, 3456)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing gardens:");
    card = gardens;
    state->supplyCount[card] = 4567;
    check = state->supplyCount[card];
    if(!asserttrue(check, 4567)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing mine:");
    card = mine;
    state->supplyCount[card] = 5678;
    check = state->supplyCount[card];
    if(!asserttrue(check, 5678)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing remodel:");
    card = remodel;
    state->supplyCount[card] = 6789;
    check = state->supplyCount[card];
    if(!asserttrue(check, 6789)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing smithy:");
    card = smithy;
    state->supplyCount[card] = 7896;
    check = state->supplyCount[card];
    if(!asserttrue(check, 7896)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing village:");
    card = village;
    state->supplyCount[card] = 8967;
    check = state->supplyCount[card];
    if(!asserttrue(check, 8967)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing baron:");
    card = baron;
    state->supplyCount[card] = 9876;
    check = state->supplyCount[card];
    if(!asserttrue(check, 9876)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }
   
    printf("Testing great hall:");
    card = great_hall;
    state->supplyCount[card] = 10000;
    check = state->supplyCount[card];
    if(!asserttrue(check, 10000)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }
 
    printf("Testing minion:");
    card = minion;
    state->supplyCount[card] = 1;
    check = state->supplyCount[card];
    if(!asserttrue(check, 1)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing steward:");
    card = steward;
    state->supplyCount[card] = 2;
    check = state->supplyCount[card];
    if(!asserttrue(check, 2)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing tribute:");
    card = tribute;
    state->supplyCount[card] = 3;
    check = state->supplyCount[card];
    if(!asserttrue(check, 3)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing ambassador:");
    card = ambassador;
    state->supplyCount[card] = 4;
    check = state->supplyCount[card];
    if(!asserttrue(check, 4)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing cutpurse:");
    card = cutpurse;
    state->supplyCount[card] = 5;
    check = state->supplyCount[card];
    if(!asserttrue(check, 5)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing embargo:");
    card = embargo;
    state->supplyCount[card] = 6;
    check = state->supplyCount[card];
    if(!asserttrue(check, 6)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing outpost:");
    card = outpost;
    state->supplyCount[card] = 7;
    check = state->supplyCount[card];
    if(!asserttrue(check, 7)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing salvager:");
    card = salvager;
    state->supplyCount[card] = 8;
    check = state->supplyCount[card];
    if(!asserttrue(check, 8)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing sea hag:");
    card = sea_hag;
    state->supplyCount[card] = 9;
    check = state->supplyCount[card];
    if(!asserttrue(check, 9)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("Testing treasure map:");
    card = treasure_map;
    state->supplyCount[card] = 10;
    check = state->supplyCount[card];
    if(!asserttrue(check, 10)){
        printf(" FAILED!\n");
    } else {
        printf(" PASSED!\n");
    }

    printf("\n");
    return 0;
}