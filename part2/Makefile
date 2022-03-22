CC = gcc
INCLUDES = -I ../part1
CFLAGS = -Wall -g $(INCLUDES)

LDFLAGS = -g -L ../part1
LDLIBS = -lmylist

reverse: reverse.o

reverse.o: reverse.c


valgrind:
        valgrind --leak-check=yes ./reverse is someone here

.PHONY: clean
clean:
        rm -rf reverse  *.o *.a *.gch

.PHONY: all
all: clean reverse valgrind
