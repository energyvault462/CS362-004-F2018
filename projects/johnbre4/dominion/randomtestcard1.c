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

int getCost(int);

int testGetCost(int card, int expectedCost)
{
 if (getCost(card) == expectedCost)
 {
     printf("correct cost: PASS (expect: %d   received: %d) when testing cost of card is %i\n", expectedCost, getCost(card), card);
     return 0;
 }
 else
 {
     printf("correct cost: FAIL (expect: %d   received: %d) when testing cost of card is %i\n", expectedCost, getCost(card), card);
     return 1;
 }
}

int main(int argc, char *argv[])
{
	int cardPrice[27] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 5, 3, 4, 2, 5, 4, 4, 4};
	int draw, n;
	int pass=0, fail=0;
	srand(time(NULL));

	for(n=0;n<1000000;n++)
	{
		draw = rand() % 27;
		if(testGetCost(draw, cardPrice[draw]) == 0)
			pass++;
		else
			fail++;
	}

	printf("Final Results: Tests Passed: %d    Test Failed: %d\n", pass, fail);



	return 0;
}
