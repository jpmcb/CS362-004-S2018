/* *********************
* Name : John McBride
* Date: May 13th 2018
* Description: Utility functions for the various unit testing and 
*       random testers
************************/ 

#include "dominion.h"
#include "dominion_helpers.h"
#include "unittesting.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// ------
// Returns true if input a and b integers are the same
// ------
int asserttrue(int a, int b){
    if(a != b){
        return 0;
    }
    else {
        return 1;
    }
}

// ------
// Returns true if input a and b integers are not the same
// ------
int assertfalse(int a, int b){
    if(a == b){
        return 0;
    }
    else {
        return 1;
    }
}

// ------
// Produces a random integer in the range of input high to low (inclusive)
// ------
int randRange(int high, int low)
{
    return (rand() % (high - low + 1)) + low;
}