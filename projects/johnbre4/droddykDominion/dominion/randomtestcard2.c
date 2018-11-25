/*
test written by Brent Johnson
OSU CS362-400 FALL 2018
*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"


int testHandCount(struct gameState *state, int expectedNumber, int expectTrue)
{
  int result = numHandCards(state);
  if(expectTrue == 1) // we are testing the values are the same
  {
    if(result == expectedNumber)  // we got the same result, which is what we expected.
    {
      printf("testHandCount(): PASS - returned expected count of %d.\n", expectedNumber);
      return 0;
    }
    else
    {
      printf("testHandCount(): FAIL - didn't return expected count of %d.\n", expectedNumber);
      return 1;
    }
  }
  else
  {
    if(result != expectedNumber)  // did not get the same value, which is what we expected.
    {
      printf("testHandCount(): PASS - Correctly returned different count of %d.\n", expectedNumber);
      return 0;
    }
    else
    {
      printf("testHandCount(): FAIL - Incorrectly returned different count from %d.\n", expectedNumber);
      return 1;
    }
  }
}

int main(int argc, char *argv[])
{
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

	int draw, n;
	int pass=0, fail=0;
	int pass2=0, fail2=0;
	srand(time(NULL));

	for(n=0;n<1000000;n++)
	{
		draw = rand() % 2;
		initializeGame(2, k, 30, &G);
		if (draw == 1) // player 1
		{
	  		if(testHandCount(&G, 5, 1) == 0)    // expect correct answer
  				pass++;
  			else
  				fail++;
		}
		else
		{
			if(testHandCount(&G, 6, 0) == 0)  // expect incorrect answer
		  		pass2++;
		  	else
		  		fail2++;
		}
	}

	printf("Final Results (player1/player2) Tests Passed: %d/%d    Test Failed: %d/%d\n", pass, pass2, fail, fail2);



	return 0;
}