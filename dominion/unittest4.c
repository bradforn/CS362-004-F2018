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


// test for the function buyCard()


int main() {
      
      struct gameState Game;
      struct gameState * t = &Game;
      
      int test = 0;
      Game.coins = 2;
      Game.numBuys = 2;
      test = buyCard(2, t);
      printf(YEL"=========================================\n");
      if(test != -1)
          printf(RED "Unit Test 3 FAIL \n" RESET" Function:" BLU " buyCard()" RESET " does not let us buy a card with 2 coins!\n" RESET);
      else
          printf(GRN "Unit Test 3 PASS \n" RESET" Function:" BLU " buyCard()" RESET " does let us buy a card with 2 coins!\n" RESET);
      
      Game.coins = 12;
      test = buyCard(2, t);
      if (test == 0)
          printf(GRN "Unit Test 3 PASS \n" RESET" Function:" BLU " buyCard()" RESET"  allows us to by cards!\n" RESET);
      else
          printf(RED "Unit Test 3 FAIL \n" RESET" Function:" BLU " buyCard()" RESET " does not allow us to by cards!\n" RESET);
      
      Game.coins = 6;
      test = buyCard(2, t);
      if(test == -1)
          printf(GRN "Unit Test 3 PASS \n" RESET" Function:" BLU " buyCard()"RESET" records buys!\n" RESET);
      else
          printf(RED "Unit Test 3 FAIL \n" RESET" Function:" BLU " buyCard()"RESET" does not record buys!\n" RESET);
          
      printf(YEL"=========================================\n");

}

