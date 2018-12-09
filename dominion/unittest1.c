#include "dominion.h"
#include <stdio.h>
#include <assert.h>



///////////////////////////////////////////////////
//Fancy Color code stuff
#define RESET  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"
/////////////////////////////////////////////////
// Test for function whoseTurn() 

int main()
{
        struct gameState Game;
        int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

        initializeGame(2, k, 1, &Game);
	
	printf(YEL"=========================================\n");
        if (whoseTurn(&Game) != 0) printf(RED "Unit Test 1 FAIL \n " RESET "Function:" BLU " whoseTurn()" RESET " has an error within it cause a failure in turn transitions.\n", RED);
        else printf(GRN "Unit Test 1 PASS \n" RESET " Function:" BLU " whoseTurn()" RESET " works!\n");
        printf(YEL"=========================================\n");
}

