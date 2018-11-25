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
{
  int player = 0;
  state->discardCount[player] = 0;
  state->deckCount[player] = 0;

  state->handCount[player] = 6;
  state->hand[player][0] = estate;      // +1
  state->hand[player][1] = duchy;       // +3
  state->hand[player][2] = province;    // +6
  state->hand[player][3] = great_hall;  // +1
  state->hand[player][4] = estate;      // +1
  state->hand[player][5] = curse;       // -1
  
  return 11;  // total points in hand
}

int setHandB(struct gameState *state)
{
  int player = 0;
  state->handCount[player] = 0;
  state->deckCount[player] = 0;

  state->discardCount[player] = 6;
  state->discard[player][0] = estate;      // +1
  state->discard[player][1] = duchy;       // +3
  state->discard[player][2] = province;    // +6
  state->discard[player][3] = great_hall;  // +1
  state->discard[player][4] = estate;      // +1
  state->discard[player][5] = curse;       // -1

;

  return 11;  // total points in hand
}

int setHandC(struct gameState *state)
{
  int player = 0;

  state->handCount[player] = 0;
  state->discardCount[player] = 0;

  state->deckCount[player] = 6;
  state->deck[player][0] = estate;      // +1
  state->deck[player][1] = duchy;       // +3
  state->deck[player][2] = province;    // +6
  state->deck[player][3] = great_hall;  // +1
  state->deck[player][4] = estate;      // +1
  state->deck[player][5] = curse;       // -1

  return 11;  // total points in hand
}

int setHandD(struct gameState *state)
{
  int player = 0;

  state->handCount[player] = 6;
  state->hand[player][0] = estate;      // +1
  state->hand[player][1] = duchy;       // +3
  state->hand[player][2] = province;    // +6
  state->hand[player][3] = great_hall;  // +1
  state->hand[player][4] = estate;      // +1
  state->hand[player][5] = curse;       // -1
  
  state->discardCount[player] = 6;
  state->discard[player][0] = estate;      // +1
  state->discard[player][1] = duchy;       // +3
  state->discard[player][2] = province;    // +6
  state->discard[player][3] = great_hall;    // +1
  state->discard[player][4] = estate;      // +1
  state->discard[player][5] = curse;       // -1

  state->deckCount[player] = 12;
  state->deck[player][0] = estate;      // +1
  state->deck[player][1] = duchy;       // +3
  state->deck[player][2] = province;    // +6
  state->deck[player][3] = province;  // +6
  state->deck[player][4] = estate;      // +1
  state->deck[player][5] = curse;       // -1
  state->deck[player][6] = estate;      // +1
  state->deck[player][7] = duchy;       // +3
  state->deck[player][8] = province;    // +6
  state->deck[player][9] = province;  // +6
  state->deck[player][10] = estate;      // +1
  state->deck[player][11] = curse;       // -1

  return 49;  // total points in hand
}

int setHandE(struct gameState *state)
{
  int player = 0;
  state->discardCount[player] = 0;
  state->deckCount[player] = 0;

  state->handCount[player] = 24;
  state->hand[player][0] = estate;      // +1
  state->hand[player][1] = duchy;       // +3 (4)
  state->hand[player][2] = province;    // +6 (10)
  state->hand[player][3] = great_hall;  // +1 (11)
  state->hand[player][4] = estate;      // +1 (12)
  state->hand[player][5] = curse;       // -1 (11)
  state->hand[player][6] = estate;      // +1 (12)
  state->hand[player][7] = duchy;       // +3 (15)
  state->hand[player][8] = province;    // +6  (21)
  state->hand[player][9] = great_hall;  // +1  (22)
  state->hand[player][10] = estate;      // +1 (23)
  state->hand[player][11] = gardens;     // +1 per 10 rounded down (later)
  state->hand[player][12] = estate;      // +1 (24)
  state->hand[player][13] = duchy;       // +3 (27)
  state->hand[player][14] = province;    // +6 (33)
  state->hand[player][15] = great_hall;  // +1 (34)
  state->hand[player][16] = estate;      // +1 (35)
  state->hand[player][17] = curse;       // -1 (34)
  state->hand[player][18] = estate;      // +1 (35)
  state->hand[player][19] = duchy;       // +3 (38)
  state->hand[player][20] = province;    // +6 (44)
  state->hand[player][21] = great_hall;  // +1 (45)
  state->hand[player][22] = estate;      // +1 (46)
  state->hand[player][23] = gardens;     // +1 per 10 rounded down (later)
  // 46 plus 2*min(24/10) = 46 + 4 = 50

  return 50;
}

void runScoreTests(int expected, int gameScore)
{
  if (expected == gameScore)
  {
    printf("scoreFor(): PASS  Expected: %d   Game Score: %d\n", expected, gameScore);
  }
  else
  {
        printf("scoreFor(): FAIL  Expected: %d   Game Score: %d\n", expected, gameScore);
  }
}

int main(int argc, char *argv[])
{
  struct gameState g;
  int testFor;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

  initializeGame(2, k, 31, &g);

  testFor = setHandA(&g);
  printf("Test hand score: ");
  runScoreTests(testFor, scoreFor(0, &g));

  
  testFor = setHandB(&g);
  printf("Test discard score: ");
  runScoreTests(testFor, scoreFor(0, &g));

  
  testFor = setHandC(&g);
  printf("Test deck score: ");
  runScoreTests(testFor, scoreFor(0, &g));

  testFor = setHandD(&g);
  printf("Test hand, deck and discard combined score: ");
  runScoreTests(testFor, scoreFor(0, &g));

  testFor = setHandE(&g);
  printf("Test large hand with 2 gardens score: ");
  runScoreTests(testFor, scoreFor(0, &g));

   return 0;
}