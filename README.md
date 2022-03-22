Part 1: Implement a singly linked list
--------------------------------------

(a) 

Implement a generic singly linked list that can hold
any data type.  The interface has been specified and provided to you
in a header file called mylist.h.  Write mylist.c
that implements each function whose prototype is included in mylist.h.

    struct Node *addFront(struct List *list, void *data)

    void traverseList(struct List *list, void (*f)(void *))

    void flipSignDouble(void *data)

    int compareDouble(const void *data1, const void *data2)

    struct Node *findNode(struct List *list, const void *dataSought,
            int (*compar)(const void *, const void *))

    void *popFront(struct List *list)

    void removeAllNodes(struct List *list)

    struct Node *addAfter(struct List *list, 
            struct Node *prevNode, void *data)

    void reverseList(struct List *list)

The header file contains detailed comments specifying the behavior of
the functions.  Your implementation should follow the specified
behavior.

(b)

In addition, I provide you with a test driver program, mylist-test.c, which
produces the  output for a correctly implemented linked list

Modify your Makefile to produce a static library named 'libmylist.a'
that contains your linked list object files.  Your test program,
mylist-test, must link with the library file, not the mylist.o file.

Part 2: Using the linked list library for strings
-------------------------------------------------

In this part, you will use the linked list library that you implemented in
part1 to write a program called 'reverse' that simply prints out the command
line arguments in reverse order.  In addition, it will look for the word
"dude" (case-sensitive) among the command line arguments you passed, and
report whether it's there or not.

For example,

    ./reverse hello world dude
    dude
    world
    hello

    dude found

Another example:

    ./reverse hello world friend
    friend
    world
    hello

    dude not found
