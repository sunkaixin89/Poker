CC=gcc
CFLAGS=-g
TARGET=../target/
SOURCE=../source/
all:game
	mv game $(TARGET)game

game:game.o
	 $(CC) $(CFLAGS) game.o -o game

GAMESOURCE=$(SOURCE)game.c
game.o: $(GAMESOURCE)
	$(CC) $(CFLAGS) -c $(GAMESOURCE) 

clean:
	rm game.o
