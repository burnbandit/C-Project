CC = gcc
CFLAGS = -Wall -g #don't use -I, -l, -L flags
LDFLAGS = -g

mylist-test: mylist-test.o libmylist.a

libmylist.a: mylist.o
        ar rcs libmylist.a mylist.o

mylist-test.o: mylist-test.c mylist.h

mylist.o: mylist.c mylist.h

valgrind:
        valgrind --leak-check=yes ./mylist-test

.PHONY: clean
clean:
        rm -rf mylist-test *.o *.a *.gch

.PHONY: all
all: clean mylist-test valgrind
