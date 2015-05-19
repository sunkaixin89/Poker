all:test

test:test.o common.o
	g++ -g  test.o common.o -o test

test.o:test.cpp
	g++ -g -c test.cpp -o test.o
common.o:common.cpp
	g++ -g -c common.cpp -o common.o
