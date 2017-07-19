CC=g++
CFLAGS=-I/dbg/include/

all:
	g++ -g -O0 test.cpp $(CFLAGS) -L/dbg/lib -lfst -std=c++11 -ldl