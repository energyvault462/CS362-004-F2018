/*
test written by Brent Johnson
OSU CS362-400 FALL 2018
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"


int setHandA(struct gameState *state)
{ // gives player hand 4 coppers and 1 smithy
  int player = 0;
  state->discardCount[player] = 0;

  state->handCount[player] = 5;
  state->hand[player][0] = copper;    
  state->hand[player][1] = copper;    
  state->hand[player][2] = copper;    
  state->hand[player][3] = copper;  
  state->hand[player][4] = smithy;  

  state->deckCount[player] = 6;
  state->deck[player][0] = copper;    
  state->deck[player][1] = copper;    
  state->deck[player][2] = copper;    
  state->deck[player][3] = estate;  
  state->deck[player][4] = estate;
  state->deck[player][5] = estate;

  return 7;  // total coin for this action
}

int setHandB(struct gameState *state)
{ // gives player hand 5 coppers
  int player = 0;
  state->discardCount[player] = 0;

  state->handCount[player] = 5;
  state->hand[player][0] = copper;    
  state->hand[player][1] = copper;    
  state->hand[player][2] = copper;    
  state->hand[player][3] = copper;  
  state->hand[player][4] = copper;  

  state->deckCount[player] = 6;
  state->deck[player][0] = copper;    
  state->deck[player][1] = copper;    
  state->deck[player][2] = copper;    
  state->deck[player][3] = estate;  
  state->deck[player][4] = estate;
  state->deck[player][5] = smithy;

  return 5;  // total coin for this action
}


int testPlaySmithy(struct gameState *state)
{
    int money = 0;
    int smithyPos = -1;
    int i;
    for (i = 0; i < numHandCards(state); i++) {
      if (handCard(i, state) == copper)
        money++;
      else if (handCard(i, state) == silver)
        money += 2;
      else if (handCard(i, state) == gold)
        money += 3;
      else if (handCard(i, state) == smithy)
        smithyPos = i;
    }


    playCard(smithyPos, -1, -1, -1, state);


    return state->handCount[0];

}

void printResults(int expected, int result)
{
  if(result == expected)
  {
    printf("playSmithy(): PASS  Expected %d cards, have %d.\n", expected, result);
  }
  else
  {
    printf("playSmithy(): FAIL  Expected %d cards, have %d.\n", expected, result);
  }
}


int main(int argc, char *argv[])
{
  struct gameState g;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
  int result, expected;

  initializeGame(2, k, 31, &g);
  

  expected = setHandA(&g);
  result=testPlaySmithy(&g);
  printResults(expected, result);

  expected = setHandB(&g);
  result=testPlaySmithy(&g);
  printResults(expected, result);
 


   return 0;
}