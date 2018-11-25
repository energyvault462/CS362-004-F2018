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
  printf("Decks setup as -- hand: 4 gold, 1 feast; deck: 6 copper; discard: empty\n");
  int player = 0;
  state->discardCount[player] = 0;

  state->handCount[player] = 5;
  state->hand[player][0] = copper;    
  state->hand[player][1] = copper;    
  state->hand[player][2] = copper;    
  state->hand[player][3] = copper;  
  state->hand[player][4] = feast;  

  state->deckCount[player] = 6;
  state->deck[player][0] = estate;    
  state->deck[player][1] = estate;    
  state->deck[player][2] = estate;    
  state->deck[player][3] = estate;  
  state->deck[player][4] = estate;
  state->deck[player][5] = estate;

  return 5;  // total coin for this action
}

int setHandB(struct gameState *state)
{ // gives player hand 5 coppers
  printf("Decks setup as -- hand: 5 copper; deck: council_room, 2 copper, 3 estates; discard: gold\n");
  int player = 0;
  state->discardCount[player] = 0;

  state->handCount[player] = 5;
  state->hand[player][0] = copper;    
  state->hand[player][1] = copper;    
  state->hand[player][2] = copper;    
  state->hand[player][3] = copper;  
  state->hand[player][4] = copper; 

  state->deckCount[player] = 6;
  state->deck[player][0] = council_room;    
  state->deck[player][1] = copper;    
  state->deck[player][2] = copper;    
  state->deck[player][3] = estate;  
  state->deck[player][4] = estate;
  state->deck[player][5] = estate;

  state->discardCount[player] = 1;
  state->deck[player][0] = gold; 

  return 5;  // total coin for this action
}

int setHandC(struct gameState *state)
{ // gives player hand 5 coppers
  printf("Decks setup as -- hand: 5 copper; deck: 5 copper; discard: council_room\n");
  int player = 0;
  state->discardCount[player] = 0;

  state->handCount[player] = 5;
  state->hand[player][0] = copper;    
  state->hand[player][1] = copper;    
  state->hand[player][2] = copper;    
  state->hand[player][3] = copper;  
  state->hand[player][4] = copper;  

  state->deckCount[player] = 5;
  state->deck[player][0] = copper;    
  state->deck[player][1] = copper;    
  state->deck[player][2] = copper;    
  state->deck[player][3] = copper;  
  state->deck[player][4] = copper;

  state->discardCount[player] = 1;
  state->deck[player][0] = council_room; 

  return 5;  // total coin for this action
}


int countMoney(struct gameState *state)
{
  int i, money = 0;

  for (i = 0; i < numHandCards(state); i++) {
    if (handCard(i, state) == copper)
      money++;
    else if (handCard(i, state) == silver)
      money += 2;
    else if (handCard(i, state) == gold)
      money += 3;
  }

  return money;
}

int lookForNonCopper(struct gameState *state)
{
  int i, notCopper=0;
  for (i = 0; i < numHandCards(state); i++)
  {
    if(handCard(i, state) != copper && handCard(i, state) != feast)
      notCopper++;
  }
  return notCopper;
}

int testPlayCard(struct gameState *state)
{
    int money = 0;
    int testCardPos = -1;
    int i;
    for (i = 0; i < numHandCards(state); i++) {
      if (handCard(i, state) == copper)
        money++;
      else if (handCard(i, state) == silver)
        money += 2;
      else if (handCard(i, state) == gold)
        money += 3;
      else if (handCard(i, state) == feast)
        testCardPos = i;
    }

    playCard(testCardPos, -1, -1, -1, state);


    return state->handCount[0];

}

void printResults(int expected, int result)
{
  if(result == expected)
  {
    printf("play council_room(): PASS  Expected %d cards, have %d.\n", expected, result);
  }
  else
  {
    printf("play council_room(): FAIL  Expected %d cards, have %d.\n", expected, result);
  }
}


int main(int argc, char *argv[])
{
  struct gameState g;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
  int result, expected;
  int i;

  initializeGame(2, k, 31, &g);
  

  expected = setHandA(&g);
  result = testPlayCard(&g);
  printResults(expected, result);

  printf("Test something other than copper in hand: ");
  result = lookForNonCopper(&g);
  if(result > 0)
  {
    printf("PASS Expected hand to have something other than copper and feast.\n");
  }
  else {
    printf("FAIL Expected hand to have something other than copper and feast.\n");    
  }


  initializeGame(2, k, 31, &g);
  expected = setHandB(&g);
  result = testPlayCard(&g);
  printResults(expected, result);
  printf("Test something other than copper in hand: ");
  result = lookForNonCopper(&g);
  if(result == 0)
  {
    printf("PASS Expected hand to have only copper and feast.\n");
  }
  else {
    printf("FAIL Expected hand to have only copper and feast.\n");    
  }


  initializeGame(2, k, 31, &g);
  expected = setHandC(&g);
  result = testPlayCard(&g);
  printResults(expected, result);
  printf("Test something other than copper in hand: ");
  result = lookForNonCopper(&g);
  if(result == 0)
  {
    printf("PASS Expected hand to have only copper and feast.\n");
  }
  else {
    printf("FAIL Expected hand to have only copper and feast.\n");    
  }



   return 0;
}