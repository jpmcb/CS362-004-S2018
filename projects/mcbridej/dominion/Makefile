# John McBride
# CS 362 - Software Engineering II
# Spring 2018

CFLAGS = -Wall -fpic -coverage -lm 

smithy.o: refactored.h smithy.c
	gcc -c smithy.c -g $(CFLAGS)

adventurer.o: refactored.h adventurer.c
	gcc -c adventurer.c -g $(CFLAGS)

village.o: refactored.h village.c
	gcc -c village.c -g $(CFLAGS)

treasure_map.o: refactored.h treasure_map.c
	gcc -c treasure_map.c -g $(CFLAGS)

gardens.o: refactored.h gardens.c
	gcc -c gardens.c -g $(CFLAGS)

CARD_OBJS = smithy.o adventurer.o village.o treasure_map.o gardens.o

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c ${CARD_OBJS}
	gcc -o playdom playdom.c -g dominion.o rngs.o ${CARD_OBJS} $(CFLAGS)

# ----------
# FUNCTION UNIT TESTS
# ----------
unittest1: unittest1.c ${CARD_OBJS} dominion.o unittesting.c unittesting.h
	gcc -o unittest1 -g unittesting.c unittest1.c ${CARD_OBJS} dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c ${CARD_OBJS} dominion.o unittesting.c unittesting.h
	gcc -o unittest2 -g unittesting.c unittest2.c ${CARD_OBJS} dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c ${CARD_OBJS} dominion.o unittesting.c unittesting.h
	gcc -o unittest3 -g unittesting.c unittest3.c ${CARD_OBJS} dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c ${CARD_OBJS} dominion.o unittesting.c unittesting.h
	gcc -o unittest4 -g unittesting.c unittest4.c $(CARD_OBJS) dominion.o rngs.o $(CFLAGS)

# ---------
# CARD UNIT TESTS
# ---------
cardtest1: cardtest1.c ${CARD_OBJS} dominion.o unittesting.c unittesting.h
	gcc -o cardtest1 -g unittesting.c cardtest1.c ${CARD_OBJS} dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c ${CARD_OBJS} dominion.o unittesting.c unittesting.h
	gcc -o cardtest2 -g unittesting.c cardtest2.c ${CARD_OBJS} dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c ${CARD_OBJS} dominion.o unittesting.c unittesting.h
	gcc -o cardtest3 -g unittesting.c cardtest3.c ${CARD_OBJS} dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c ${CARD_OBJS} dominion.o unittesting.c unittesting.h
	gcc -o cardtest4 -g unittesting.c cardtest4.c ${CARD_OBJS} dominion.o rngs.o $(CFLAGS)

# --------
# Generate unit test outfile 
# --------
unittestresults.out:
	echo "unittest1.c:" >> unittestresults.out
	make unittest1
	./unittest1 >> unittestresults.out
	gcov unittest1.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest2.c:" >> unittestresults.out
	make unittest2
	./unittest2 >> unittestresults.out
	gcov unittest2.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest3.c:" >> unittestresults.out
	make unittest3
	./unittest3 >> unittestresults.out
	gcov unittest3.c >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest4.c:" >> unittestresults.out
	make unittest4
	./unittest4 >> unittestresults.out
	gcov unittest4.c >> unittestresults.out
	gcov dominion.c >> unittestresults.outests.out

	echo "cardtest1.c:" >> unittestresults.out
	make cardtest1
	./cardtest1 >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
	gcov smithy.c >> unittestresults.out

	echo "cardtest2.c:" >> unittestresults.out
	make cardtest2
	./cardtest2 >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out
	gcov adventurer.c >> unittestresults.out

	echo "cardtest3.c:" >> unittestresults.out
	make cardtest3
	./cardtest3 >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out
	gcov village.c >> unittestresults.out

	echo "cardtests4.c:" >> unittestresults.out
	make cardtest4 
	./cardtest4 >> unittestresults.out
	gcov cardtest4.c >> unittestresults.out
	gcov gardens.c >> unittestresults.out

# -----------
# Random testing rules
# -----------

randtest1: randomtestcard1.c ${CARD_OBJS} dominion.o unittesting.c unittesting.h interface.c interface.h
	gcc -o randtest1 -g unittesting.c randomtestcard1.c interface.c ${CARD_OBJS} dominion.o rngs.o $(CFLAGS)

randtest2: randomtestcard2.c ${CARD_OBJS} dominion.o unittesting.c unittesting.h interface.c interface.h
	gcc -o randtest2 -g unittesting.c randomtestcard2.c interface.c ${CARD_OBJS} dominion.o rngs.o $(CFLAGS)

randtest3: randomtestcard3.c ${CARD_OBJS} dominion.o unittesting.c unittesting.h interface.c interface.h
	gcc -o randtest3 -g unittesting.c randomtestcard3.c interface.c ${CARD_OBJS} dominion.o rngs.o $(CFLAGS)


# -----------
# Random automated tests & output files
# -----------

randtests:
	echo "randomtestcard1.c:" >> randomtestcard1.out 
	make randtest1
	./randtest1 >> randomtestcard1.out 
	gcov randomtestcard1.c >> randomtestcard1.out 
	gcov smithy.c >> randomtestcard1.out

	echo "randomtestcard2.c:" >> randomtestcard2.out 
	make randtest2
	./randtest2 >> randomtestcard2.out 
	gcov randomtestcard2.c >> randomtestcard2.out 
	gcov village.c >> randomtestcard2.out

	echo "randomtestcard3.c:" >> randomtestcard3.out 
	make randtest3
	./randtest3 >> randomtestcard3.out 
	gcov randomtestcard3.c >> randomtestcard3.out 
	gcov adventurer.c >> randomtestcard3.out

#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o ${CARD_OBJS}
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o ${CARD_OBJS} $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o ${CARD_OBJS}
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o ${CARD_OBJS} $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o ${CARD_OBJS}
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o ${CARD_OBJS} $(CFLAGS)

testAll: dominion.o testSuite.c ${CARD_OBJS}
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o ${CARD_OBJS} $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o ${CARD_OBJS}
	gcc -o player player.c -g  dominion.o rngs.o interface.o ${CARD_OBJS} $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
	rm -f unittest1 unittest2 unittest3 unittest4
	rm -f cardtest1 cardtest2 cardtest3 cardtest4
	rm -f unittestresults.out
	rm -f randtest1 randtest2 randtest3