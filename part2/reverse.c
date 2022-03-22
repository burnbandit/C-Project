#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylist.h"

void print(void *p)
{
        printf("%s\n", (char *)p);
}


int main(int argc, char **argv)
{
        struct List q;
        initList(&q);
        argv++;

        while(*argv)
        {
                addFront(&q, *(argv));
                argv++;
        }

        traverseList(&q, &print);

        if((*findNode)(&q, "dude", (int(*)(const void*, const void*))(strcmp))==0)
        {
                printf("\ndude not found\n");
                printf("\n");
        }
        else
        {
                printf("\ndude found\n");
                printf("\n");
        }

        removeAllNodes(&q);
}
