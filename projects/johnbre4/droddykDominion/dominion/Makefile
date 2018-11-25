CFLAGS= -Wall -fpic -coverage -lm -std=c99

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/


rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	
randomtestresults: dominion.c rngs.c
	echo "random test 1" > randomtestcard1.out
	echo "" >> randomtestcard1.out
	echo "Result for running dominion tests:" >> randomtestcard1.out
	echo "randomtestcard1.c" >> randomtestcard1.out
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> randomtestcard1.out
	gcov -b randomtestcard1.c >> randomtestcard1.out
	gcov -b dominion.c >> randomtestcard1.out
	cat randomtestcard1.c.gcov >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

	echo "random test 2" > randomtestcard2.out
	rm -f dominion.c.gcov
	echo "" >> randomtestcard2.out
	echo "Result for running dominion tests:" >> randomtestcard2.out
	echo "randomtestcard2.c" >> randomtestcard2.out
	gcc -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> randomtestcard2.out
	gcov -b randomtestcard2.c >> randomtestcard2.out
	gcov -b dominion.c >> randomtestcard2.out
	cat randomtestcard2.c.gcov >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

	echo "random test adventurer" > randomtestadventurer.out
	rm -f dominion.c.gcov
	echo "" >> randomtestadventurer.out
	echo "Result for running dominion tests:" >> randomtestadventurer.out
	echo "randomtestadventurer.c" >> randomtestadventurer.out
	gcc -o randomtestadventurer dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	gcov -b randomtestadventurer.c >> randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out
	cat randomtestadventurer.c.gcov >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

johnbre4tests: dominion.c rngs.c unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c dominion.c rngs.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c
	echo "random test 1" > randomtestcard1.out
	echo "" >> randomtestcard1.out
	echo "Result for running dominion tests:" >> randomtestcard1.out
	echo "randomtestcard1.c" >> randomtestcard1.out
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> randomtestcard1.out
	gcov -b randomtestcard1.c >> randomtestcard1.out
	gcov -b dominion.c >> randomtestcard1.out
	cat randomtestcard1.c.gcov >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

	echo "random test 2" > randomtestcard2.out
	rm -f dominion.c.gcov
	echo "" >> randomtestcard2.out
	echo "Result for running dominion tests:" >> randomtestcard2.out
	echo "randomtestcard2.c" >> randomtestcard2.out
	gcc -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> randomtestcard2.out
	gcov -b randomtestcard2.c >> randomtestcard2.out
	gcov -b dominion.c >> randomtestcard2.out
	cat randomtestcard2.c.gcov >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

	echo "random test adventurer" > randomtestadventurer.out
	rm -f dominion.c.gcov
	echo "" >> randomtestadventurer.out
	echo "Result for running dominion tests:" >> randomtestadventurer.out
	echo "randomtestadventurer.c" >> randomtestadventurer.out
	gcc -o randomtestadventurer dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	gcov -b randomtestadventurer.c >> randomtestadventurer.out
	gcov -b dominion.c >> randomtestadventurer.out
	cat randomtestadventurer.c.gcov >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

	echo "unit test 1" > unittestresult.out
	echo "" >> unittestresult.out
	echo "Result for running dominion tests:" >> unittestresult.out
	echo "unittest1.c:" >> unittestresult.out
	gcc -o unittest1 dominion.c rngs.c unittest1.c $(CFLAGS)
	./unittest1 >> unittestresult.out
	gcov -b unittest1.c >> unittestresult.out

	gcc -o unittest2 dominion.c rngs.c unittest2.c $(CFLAGS)
	echo "" >> unittestresult.out
	echo "" >> unittestresult.out
	echo "unit test 2" >> unittestresult.out
	./unittest2 >> unittestresult.out
	gcov -b unittest2.c >> unittestresult.out

	gcc -o unittest3 dominion.c rngs.c unittest3.c $(CFLAGS)
	echo "" >> unittestresult.out
	echo "" >> unittestresult.out
	echo "unit test 3" >> unittestresult.out
	./unittest3 >> unittestresult.out
	gcov -b unittest3.c >> unittestresult.out


	gcc -o unittest4 dominion.c rngs.c unittest4.c $(CFLAGS)
	echo "" >> unittestresult.out
	echo "" >> unittestresult.out
	echo "unit test 4" >> unittestresult.out
	./unittest4 >> unittestresult.out
	gcov -b unittest4.c >> unittestresult.out

	gcc -o cardtest1 dominion.c rngs.c cardtest1.c $(CFLAGS)
	echo "" >> unittestresult.out
	echo "" >> unittestresult.out
	echo "card test 1" >> unittestresult.out
	./cardtest1 >> unittestresult.out
	gcov -b cardtest1.c >> unittestresult.out

	gcc -o cardtest2 dominion.c rngs.c cardtest2.c $(CFLAGS)
	echo "" >> unittestresult.out
	echo "" >> unittestresult.out
	echo "card test 2" >> unittestresult.out
	./cardtest2 >> unittestresult.out
	gcov -b cardtest2.c >> unittestresult.out

	gcc -o cardtest3 dominion.c rngs.c cardtest3.c $(CFLAGS)
	echo "" >> unittestresult.out
	echo "" >> unittestresult.out
	echo "card test 3" >> unittestresult.out
	./cardtest3 >> unittestresult.out
	gcov -b cardtest3.c >> unittestresult.out

	gcc -o cardtest4 dominion.c rngs.c cardtest4.c $(CFLAGS)
	echo "" >> unittestresult.out
	echo "" >> unittestresult.out
	echo "card test 4" >> unittestresult.out
	./cardtest4 >> unittestresult.out
	gcov -b cardtest4.c >> unittestresult.out

	echo "" >> unittestresult.out
	echo "" >> unittestresult.out
	gcov -b dominion.c >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe  randomtest1 randomtest2 randomtestadventurer unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
