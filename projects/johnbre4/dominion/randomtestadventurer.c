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

void setHand(struct gameState *state)
{
  int i;

  int player = 0;

  state->handCount[player] = 5;
  state->discardCount[player] = 3;
  state->deckCount[player] = 6;
  state->discard[player][0] = copper;
  state->discard[player][1] = silver;
  state->discard[player][2] = gold;



  for(i=0; i< 5; i++)
  {
    state->hand[player][i] = rand() % 27;
    state->deck[player][i] = rand() % 27;
  }

}

int countTreasure(struct gameState *state)
{
  int i, count=0;
  int player = 0;
  for(i=0;i<state->handCount[0];i++)
    if(state->hand[player][i] == copper || state->hand[player][i] == silver || state->hand[player][i] == gold)
      count++;

  return count;
}

int checkHandForAdventurer(struct gameState *state)
{
  int i;
  int player = 0;
  for(i=0;i<5;i++)
  {
    if(state->hand[player][i] == adventurer)
    {
      return i;
    }
  }

  return -1;
}

int printResults(int expected, int result)
{
  if(result == expected)
  {
    printf("PASS  Expected %d treasure cards, have %d.\n", expected, result);
    return 0;
  }
  else
  {
    printf("FAIL  Expected %d treasure cards, have %d.\n", expected, result);
    return 1;
  }
}


int main(int argc, char *argv[])
{
  struct gameState g;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
  int result, expected, pass=0, fail=0, adventurerPos, n;
  srand(time(NULL));

  for(n=0;n<1000000;n++)
  {
    initializeGame(2, k, 31, &g);
    setHand(&g);
    expected = countTreasure(&g);
    adventurerPos = checkHandForAdventurer(&g);

    //printf("Hand Starts ---------------------------\n");
    //for(n=0;n<g.handCount[0];n++)
    //{
    //  printf("hand[%d]: %d\n", n, g.hand[0][n]);
    //}

    if(adventurerPos > -1)
    {
      expected = expected+2;
      playCard(adventurerPos, -1, -1, -1, &g);
      printf("adventurer: ");
    }
    else
    {
      printf("            ");
    }

    result = countTreasure(&g);

    if(printResults(expected, result) == 0)
    {
      pass++;
    }
    else
    {
      fail++;
    }
    //printf("Hand finishes ---------------------------\n");
    //for(n=0;n<g.handCount[0];n++)
    //{
    //  printf("hand[%d]: %d\n", n, g.hand[0][n]);
    //}
    //printf("hand count %d\n", g.handCount[0]);
    //printf("----------------------------------------\n");
    //printf("----------------------------------------\n");

  }

    printf("Final Results: Tests Passed: %d    Test Failed: %d\n", pass, fail);
 


   return 0;
}