/**************
* Name: John McBride
* Date: May 13th 2018
* Description: Adventure card random tester
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

    // Initilize variables needed for loop counters, test tracking,
    // and the game state
    int i, j, k, handsize, game, decksize, returned, drawntreasure, randSeeding, numPlayers;
    int preHandCount, preTreasure, postTreasure;

    struct gameState *state = 0;

    // Empty pointers to the players hand and the players deck 
    int *hand = 0;
    int *deck = 0; 

    // Arbitray hand of cards for the tester
    int cards[10] = {adventurer, council_room, feast, gardens,
        mine, remodel, smithy, village, baron, great_hall};

    // Set up the temporary hand
    int temphand[MAX_HAND];
    for(int i = 0; i < MAX_HAND; i++){
        temphand[i] = -1;
    }

    printf("Testing adventurer card! \n");
    printf("RANDOM TESTS:\n");

    // Perform the tests
    for(i = 0; i < 2000; i++)
    {
        printf("On test: %d\n", i);

        // Initilized game variables 
        randSeeding = randRange(1000, 1);
        numPlayers = randRange(4, 2);
        drawntreasure = 0;

        // Initilize the state
        state = 0;
        state = newGame();
        game = initializeGame(numPlayers, cards, randSeeding, state);

        //set up the players hands and decks
        for(j = 0; j < numPlayers; j++)
        {
            // Random hand size
            handsize = randRange(MAX_HAND, 0);

            hand = malloc(sizeof(int) * handsize);

            // Initilize the hand
            for(k = 0; k < handsize; k++)
            {
                // Random cards in hand (int casts to the enum card data type)
                hand[k] = randRange(26, 0);
            }

            // Random deck size
            decksize = randRange(MAX_DECK, 0);

            deck = malloc(sizeof(int) * decksize);

            // Initlize the deck
            for(k = 0; k < decksize; k++)
            {
                // Random cards in deck (int casts to enum card data type)
                deck[k] = randRange(26, 0);
            }

            // Copy the memory over into the state struct
            memcpy(state->hand[j], hand, sizeof(int) * handsize);
            memcpy(state->deck[j], deck, sizeof(int) * decksize);
            state->handCount[j] = handsize;
            state->deckCount[j] = decksize;

            // Clean up
            free(deck);
            free(hand); 
        }

        // Perform tests for each player
        for(j = 0; j < numPlayers; j++)
        {
            // set the players turn for this round of testing
            state->whoseTurn = j;

            // Check how many treasures are in the players hand currently
            preTreasure = 0;
            for(k = 0; k < state->handCount[j]; k++)
            {
                if(state->hand[j][k] == copper || state->hand[j][k] == silver || state->hand[j][k] == gold)
                {
                    preTreasure++; 
                }
            }

            // Check to see how many cards are currently in hand
            preHandCount = state->handCount[j];

            // Test the adventure card function (can be found in adventurecard.c)
            returned = caseAdventurer(temphand, drawntreasure, state, j);

            // Check how many treasures are in the players hand after function ran
            postTreasure = 0;
            for(k = 0; k < state->handCount[j]; k++)
            {
                if(state->hand[j][k] == copper || state->hand[j][k] == silver || state->hand[j][k] == gold)
                {
                    postTreasure++; 
                }
            }
            
            // Check that there are now 2 more cards in the players hand 
            if(!asserttrue((preHandCount + 2), state->handCount[j]))
            {
                printf("Case FAILED! -- Wrong hand count!\n");
                printf("Pre hand count: %d   Current hand count: %d\n", preHandCount, state->handCount[j]);
                printf("drawntrasure: %d\n", drawntreasure);
                printf("number of players: %d\n", numPlayers);
                printf("failed on player: %d\n", (j + 1));
                printf("Player hand size: %d\n", state->handCount[j]);
                printf("Player deck size: %d\n", state->deckCount[j]);
                printf("Player hand: \n");
                printHand(j, state);
                printf("Player deck: \n");
                printDeck(j, state);
                printf("Game state: \n");
                printState(state);
            }

            // Check to ensure that there are now 2 more treasure cards in hand
            if(!asserttrue(preTreasure + 2, postTreasure)) 
            {
                printf("Case FAILED! -- Wrong number of treasure cards!\n");
                printf("Pre treasure: %d  Post treasure: %d\n", preTreasure, postTreasure);
                printf("drawntrasure: %d\n", drawntreasure);
                printf("number of players: %d\n", numPlayers);
                printf("failed on player: %d\n", (j + 1));
                printf("Player hand size: %d\n", state->handCount[j]);
                printf("Player deck size: %d\n", state->deckCount[j]);
                printf("Player hand: \n");
                printHand(j, state);
                printf("Player deck: \n");
                printDeck(j, state);
                printf("Game state: \n");
                printState(state);
            } 
        }
              
        free(state);
    }
}