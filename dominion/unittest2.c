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


// test for the function kingdomCards()


int main() {
      int k[10] = {1,2,3,4,5,6,7,8,9,10};

      int* result = kingdomCards(k[0], k[1], k[2], k[3], k[4], k[5], k[6], k[7], k[8], k[9]);
      int errorflag = 0;
      int i = 0;

      printf(YEL"=========================================\n");

      while( i < 10 ){
        if(result[i] != k[i]){
          errorflag = 1;
          printf(RED "Unit Test 2 FAIL \n" RESET" Function:" BLU " kingdomCards()" RESET " has failed to keep track of the array values for the cards!\n");
        }
        i = i + 1;
      }
      if(errorflag != 1){
        printf(GRN "Unit Test 2 PASS \n" RESET" Function:" BLU " kingdomCards()" RESET " works!\n");
      }
      printf(YEL"=========================================\n");

}
