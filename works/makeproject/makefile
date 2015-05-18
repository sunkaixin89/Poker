CC=g++
CFLAGS= -g -c
TARGET=../target
SOURCE=../source

all:game

OBJS = game.o msg.o pokerGame.o mainStrategy.o

game : $(OBJS)
	$(CC) -g -o $(TARGET)/game $(OBJS)

game.o : $(SOURCE)/game.cpp
	$(CC) $(CFLAGS) -o $@ $<
		
msg.o : $(SOURCE)/msg.cpp
	$(CC) $(CFLAGS) -o $@ $<

pokerGame.o:$(SOURCE)/pokerGame.cpp
	$(CC) $(CFLAGS) -o $@ $<

strategy.o :$(SOURCE)/strategy.cpp
	$(CC) $(CFLAGS) -o $@ $<

mainStrategy.o:$(SOURCE)/MainStrategy.cpp
	$(CC) $(CFLAGS) -o $@ $<
	
clean:
	rm *.o
