#include "dominion.h"
#include "dominion_helpers.h"
#include <strinGame.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

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


int main() {
////////////////////////////////////////////////////////////////////////////////
//declairing my varibles
    struct gameState Game;
    int seed = 1000;
    int numPlayers = 2;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy, council_room};
    int i, j, z, m, x, randomCard, randomHand, deckSize, handSize, 
        coinCount, discardCopper, discardSilver, discardGold, coinCountPre,
        testPassed, drawFailure, discardFailure, curPlayer;
    curPlayer = testPassed = drawFailure = discardFailure = 0;
    clock_t startTime = clock();
    srand(time(NULL));
////////////////////////////////////////////////////////////////////////////////
//The main for loop 
    for(i = 0; i < 5; i++)
    {
        initializeGame(numPlayers, k, seed, &Game);
        coinCountPre = 0;
        deckSize = rand() % (MAX_DECK + 1);
        handSize = rand() % (deckSize + 1);

        Game.deckCount[0] = deckSize - handSize;
        Game.handCount[0] = handSize;
        
        ////////////////////////////////////////////////////////////////////////
        for (j = 0; j < numPlayers; j++)
        {
            for(z = 0;z < Game.deckCount[j]; z++)
            {
                randomCard = rand() % (50 + 1);
                randomHand = rand() % (10);
                if(randomCard == 1)
                    Game.deck[j][z] = copper;
                else if(randomCard == 2)
                    Game.deck[j][z] = silver;
                else if(randomCard == 3)
                    Game.deck[j][z] = gold;
                else 
                    Game.deck[j][z] = k[randomHand];
            }
        }  
        ////////////////////////Coin Count Modifier/////////////////////////////
        for(m = 0; m < Game.handCount[curPlayer]; m++)
        {
            if(Game.hand[curPlayer][m] == copper || Game.hand[curPlayer][m] == silver || Game.hand[curPlayer][m] == gold)
                coinCountPre++;
        }

        adventurerCard(curPlayer, &Game);
        coinCount = 0;

        for(m = 0; m < Game.handCount[curPlayer]; m++)
        {
            if(Game.hand[curPlayer][m] == copper || Game.hand[curPlayer][m] == silver || = Game.hand[curPlayer][m] == gold)
                coinCount++;
        }    
        //////////////////////////Coin Discarder////////////////////////////////
        discardCopper = 0;
        discardSilver = 0;
        discardGold = 0;
        for(x = 0; x < Game.discardCount[curPlayer]; x++)
        {
            if(Game.discard[curPlayer][x] == copper) {
                discardCopper++;
            } else if(Game.discard[curPlayer][x] == silver) {
                discardSilver++;
            } else if(Game.discard[curPlayer][x] == gold) {
                discardGold++;
            }
        }        
        ////////////////////////////Tests//////////////////////////////////////
        int passed = 1;
        printf(YEL"=========================================\n");
        printf(YEL"===============Test Case-%d===============\n", i);

        if( coinCount > ( coinCountPre + 2 ) ){
            printf(RED "FAIL: " RESET "Too many cards have been drawn\n");
            drawFailure++;
            passed = 0;
        }

        if( coinCount < coinCountPre ){
            printf(RED "FAIL: " RESET "Cards are missing without cause!\n");
            drawFailure++;
            passed = 0;
        }

        if( discardCopper != 0 ){
            printf(RED "FAIL: " RESET "Copper has been discarded\n");
            discardFailure++;
            passed = 0;
        }
        
        if( discardSilver != 0 ){
            printf(RED "FAIL: " RESET "Silver has been discarded\n");
            discardFailure++;
            passed = 0;
        }
        
        if( discardGold != 0 ){
            printf(RED "FAIL: " RESET "Gold has been discarded\n");
            discardFailure++;
            passed = 0;
        }
        
        if( passed == 1 ){
            printf(GRN "Success: " RESET " all test have passed!\n");
            testPassed++;
        }
        printf(YEL"=========================================\n");

    }


    
//////////////////////////////////Results///////////////////////////////////////
    printf("\n\n\n\n");
    printf(YEL"==============Test Results===============\n");
    printf( GRN " %d Test(s) Passed\n", testPassed);
    printf( RED " %d Card(s) Drawn To Hand Failed\n", drawFailure);
    printf( RED " %d Adventurer Card(s) Failed to Discarded. \n", discardFailure);
    printf(YEL"=========================================\n");
    printf(YEL"==================Time===================\n");
    clock_t endTime = clock();
    printf( CYN " %f seconds has passed\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);
    
    printf(YEL"=========================================\n");
    
    return 0;
}
