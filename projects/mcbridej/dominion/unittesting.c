/* *********************
* Name : John McBride
* Date: 
* Description:
************************/ 

#include "dominion.h"
#include "dominion_helpers.h"
#include "unittesting.h"
#include <string.h>
#include <stdio.h>

int asserttrue(int a, int b){
    if(a != b){
        return 0;
    }
    else {
        return 1;
    }
}

int assertfalse(int a, int b){
    if(a == b){
        return 0;
    }
    else {
        return 1;
    }
}