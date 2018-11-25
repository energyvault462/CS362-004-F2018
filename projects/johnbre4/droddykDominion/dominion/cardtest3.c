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
  printf("Decks setup as -- hand: 4 gold, 1 council_room; deck: 6 gold; discard: empty\n");
  int player = 0;
  state->discardCount[player] = 0;

  state->handCount[player] = 5;
  state->hand[player][0] = gold;    
  state->hand[player][1] = gold;    
  state->hand[player][2] = gold;    
  state->hand[player][3] = gold;  
  state->hand[player][4] = council_room;  

  state->deckCount[player] = 6;
  state->deck[player][0] = gold;    
  state->deck[player][1] = gold;    
  state->deck[player][2] = gold;    
  state->deck[player][3] = gold;  
  state->deck[player][4] = gold;
  state->deck[player][5] = gold;

  return 8;  // total coin for this action
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
      else if (handCard(i, state) == council_room)
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

  initializeGame(2, k, 31, &g);
  

  expected = setHandA(&g);
  result = testPlayCard(&g);
  printResults(expected, result);
  printf("Other player drew a card: ");
  if(g.handCount[1] == 1)
  {
    printf("PASS  Expected 1 card in hand, have 1.\n");
  }
  else {
    printf("FAIL  Expected 1 card in hand, have %d.\n", g.handCount[1]);    
  }

  printf("Test number of buys: ");
  if(g.numBuys == 2)
  {
    printf("PASS  Expected 2 buys, have 2.\n");
  }
  else {
    printf("FAIL  Expected 2 buys, have %d.\n", g.numBuys);    
  }


  initializeGame(2, k, 31, &g);
  expected = setHandB(&g);
  result = testPlayCard(&g);
  printResults(expected, result);
  printf("Other player drew a card: ");
  if(g.handCount[1] == 0)
  {
    printf("PASS  Expected 0 cards in hand, have 0.\n");
  }
  else {
    printf("FAIL  Expected 0 card in hand, have %d.\n", g.handCount[1]);    
  }

  printf("Test number of buys: ");
  if(g.numBuys == 1)
  {
    printf("PASS  Expected 2 buys, have 2.\n");
  }
  else {
    printf("FAIL  Expected 2 buys, have %d.\n", g.numBuys);    
  }

  initializeGame(2, k, 31, &g);
  expected = setHandC(&g);
  result = testPlayCard(&g);
  printResults(expected, result);
  printf("Other player drew a card: ");
  if(g.handCount[1] == 0)
  {
    printf("PASS  Expected 0 cards in hand, have 0.\n");
  }
  else {
    printf("FAIL  Expected 0 card in hand, have %d.\n", g.handCount[1]);    
  }

  printf("Test number of buys: ");
  if(g.numBuys == 1)
  {
    printf("PASS  Expected 2 buys, have 2.\n");
  }
  else {
    printf("FAIL  Expected 2 buys, have %d.\n", g.numBuys);    
  }

   return 0;
}