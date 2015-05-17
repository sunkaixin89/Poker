CC=g++
CFLAGS= -g -c
TARGET=../target
SOURCE=../source
CALLGAME= -D CALL_STRATEGY
all:game cgame

COBJS= cgame.o msg.o pokerGame.o strategy.o callStrategy.o
OBJS = game.o msg.o pokerGame.o strategy.o simpleStrategy.o

cgame :$(COBJS)
	$(CC) -g -o $(TARGET)/cgame $(COBJS)
cgame.o : $(SOURCE)/game.cpp
	$(CC) $(CFLAGS) $(CALLGAME) -o $@ $<

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

callStrategy.o :$(SOURCE)/callStrategy.cpp
	$(CC) $(CFLAGS) -o $@ $<

simpleStrategy.o :$(SOURCE)/simpleStrategy.cpp
	$(CC) $(CFLAGS) -o $@ $<
clean:
	rm *.o
