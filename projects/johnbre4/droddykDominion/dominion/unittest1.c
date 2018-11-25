/*
test written by Brent Johnson
OSU CS362-400 FALL 2018
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"


int getCost(int);

void testGetCost(int card, int expectedCost, int testFor)
{
  if(testFor == 1)
  {
    if (getCost(card) == expectedCost)
        printf(" testGetCost(expect true) correct cost: PASS when testing cost of card is %i\n", expectedCost);
    else
        printf(" testGetCost(expect true) correct cost: FAIL when testing cost of card is %i\n", expectedCost);
  }
  else
  {
    if (getCost(card) != expectedCost)
        printf(" testGetCost(expect false): PASS when testing cost of card is %i\n", expectedCost);
    else
        printf(" testGetCost(expect false): FAIL when testing cost of card is %i\n", expectedCost);
  }

}

int main(int argc, char *argv[])
{
  printf("Confirm false tests work.\n");
  printf("Duchy:");
  testGetCost(duchy, 6, 0);

  printf("Confirm true tests work.\n");
  printf("curse:");
  testGetCost(curse, 0, 1);
  printf("estate:");
  testGetCost(estate, 2, 1);
  printf("duchy:");
  testGetCost(duchy, 5, 1);
  printf("province:");
  testGetCost(province, 8, 1);
  printf("copper:");
  testGetCost(copper, 0, 1);  
  printf("silver:");
  testGetCost(silver, 3, 1);
  printf("gold:");
  testGetCost(gold, 6, 1);
  printf("adventurer:");
  testGetCost(adventurer, 6, 1);
  printf("council_room:");
  testGetCost(council_room, 5, 1);
  printf("feast:");
  testGetCost(feast, 4, 1);
  printf("gardens:");
  testGetCost(gardens, 4, 1);
  printf("mine:");
  testGetCost(mine, 5, 1);
  printf("remodel:");
  testGetCost(remodel, 4, 1);
  printf("smithy:");
  testGetCost(smithy, 4, 1);
  printf("village:");
  testGetCost(village, 3, 1);
  printf("baron:");
  testGetCost(baron, 4, 1);
  printf("great_hall:");
  testGetCost(great_hall, 3, 1);
  printf("minion:");
  testGetCost(minion, 5, 1);
  printf("steward:");
  testGetCost(steward, 3, 1);
  printf("tribute:");
  testGetCost(tribute, 5, 1);
  printf("ambassador:");
  testGetCost(ambassador, 3, 1);
  printf("cutpurse:");
  testGetCost(cutpurse, 4, 1);
  printf("embargo:");
  testGetCost(embargo, 2, 1);
  printf("outpost:");
  testGetCost(outpost, 5, 1);
  printf("salvager:");
  testGetCost(salvager, 4, 1);
  printf("sea_hag:");
  testGetCost(sea_hag, 4, 1);
  printf("treasure_map:");
  testGetCost(treasure_map, 4, 1);


   return 0;
}