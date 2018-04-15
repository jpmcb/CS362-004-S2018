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
