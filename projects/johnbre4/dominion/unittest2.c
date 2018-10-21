#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"

int compareHandCount(struct gameState *state, int expectedNumber)
{
  if(numHandCards(state) == expectedNumber)
    return 1;
  else
    return 0;
}


void testHandCount(struct gameState *state, int expectedNumber, int expectTrue)
{
  int result = numHandCards(state);
  if(expectTrue == 1) // we are testing the values are the same
  {
    if(result == expectedNumber)  // we got the same result, which is what we expected.
    {
      printf("testHandCount(): PASS - returned expected count of %d.\n", expectedNumber);
    }
    else
    {
      printf("testHandCount(): FAIL - didn't return expected count of %d.\n", expectedNumber);
    }
  }
  else
  {
    if(result != expectedNumber)  // did not get the same value, which is what we expected.
    {
      printf("testHandCount(): PASS - Correctly returned different count of %d.\n", expectedNumber);
    }
    else
    {
      printf("testHandCount(): FAIL - Incorrectly returned different count from %d.\n", expectedNumber);
    }
  }
}


int main(int argc, char *argv[])
{
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

  initializeGame(2, k, 30, &G);

  testHandCount(&G, 5, 1);  // expect correct answer
  testHandCount(&G, 6, 0);  // expect incorrect answer

  G.whoseTurn = 1;
  printf("Change player, don't give them cards.\n");
  testHandCount(&G, 5, 0);  // expect incorrect answer



   return 0;
}