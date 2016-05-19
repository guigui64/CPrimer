CC = g++
CFLAGS = -Wall -g -std=c++11
BINARIES = main

all: $(BINARIES)

main.o: main.cpp Screen.hpp Window_mgr.hpp
	$(CC) $(CFLAGS) -c main.cpp
main: main.o
	$(CC) $(CFLAGS) -o main main.o

clean:
	-rm -rf *.o
distclean: clean
	-rm -rf $(BINARIES)
