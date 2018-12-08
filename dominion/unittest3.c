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


// test for the function isGameOver()


int main() {
      struct gameState Game;
      struct gameState * t = &Game;
      int k[10] = {smithy, adventurer, sea_hag, embargo, tribute, minion, ambassador, steward, embargo, baron};
     
      initializeGame(2, k, 5, &Game);
     
      int a = isGameOver(t);
      
      printf(YEL"=========================================\n");
      if(a == 1){
        printf(GRN "Unit Test 3 PASS \n" RESET" Function:" BLU " isGameOver()" RESET " works!\n");
      }
      else{
        printf(RED "Unit Test 3 FAIL \n" RESET" Function:" BLU " isGameOver()" RESET " has failed to check if the game is over!\n");
      }
      printf(YEL"=========================================\n");



}

