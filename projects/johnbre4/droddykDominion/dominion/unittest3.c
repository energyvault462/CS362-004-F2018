/*
test written by Brent Johnson
OSU CS362-400 FALL 2018
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"

void testSupplyCount(struct gameState *state, int card, int expectedNumber)
{
  if(supplyCount(card, state) == expectedNumber)
  {
    printf("supplyCount(): PASS - returned expected count of %d.\n", expectedNumber);
  }
  else
  {
    printf("supplyCount(): FAILED - returned unexpected count of %d.\n", supplyCount(card, state));
  }
}

int main(int argc, char *argv[])
{
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

  initializeGame(2, k, 30, &G);

  G.supplyCount[mine] = 3;
  testSupplyCount(&G, mine, 3);
  G.supplyCount[smithy] = 0;
  testSupplyCount(&G, smithy, 0);
  G.supplyCount[minion] = 88;
  testSupplyCount(&G, minion, 88);
  G.supplyCount[steward] = -1;
  testSupplyCount(&G, steward, -1);


   return 0;
}