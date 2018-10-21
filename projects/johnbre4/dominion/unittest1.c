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
        printf(" testGetCost(): PASS when testing cost of card is %i\n", expectedCost);
    else
        printf(" testGetCost(): FAIL when testing cost of card is %i\n", expectedCost);
	}
	else
	{
    if (getCost(card) != expectedCost)
        printf(" testGetCost(): PASS when testing cost of card is %i\n", expectedCost);
    else
        printf(" testGetCost(): FAIL when testing cost of card is %i\n", expectedCost);
	}

}

int main(int argc, char *argv[])
{
	printf("Duchy ");
   testGetCost(duchy, 5, 1);
	printf("Duchy ");
   testGetCost(duchy, 6, 0);
   return 0;
}