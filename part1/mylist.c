#include <stdio.h>
#include <stdlib.h>
#include "mylist.h"

struct Node *addFront(struct List *list, void *data)
{
        struct Node *front =(struct Node *) malloc(sizeof(struct Node));
        if(front==NULL)
        {
                perror("malloc returned NULL");
                exit(1);
        }

        front->data=data;
        front->next=list->head;
        list->head=front;
        return front;
}

void traverseList(struct List *list, void (*f)(void *))
{
        struct Node *LL=list->head;
        while (LL)
        {
                (*f)(LL->data);
                LL=LL->next;
        }
}

void flipSignDouble(void *data)
{
        *(double *)data=(*(double *)(data))*(-1);
}

int compareDouble(const void *data1, const void *data2)
{
        if(*((double *)(data1)) == *((double *)(data2)))
        {
                return 0;
        }
        else
        {
                return 1;
        }
}


struct Node *findNode(struct List *list, const void *dataSought,
                int (*compar)(const void *, const void *))
{
        struct Node *LL=(list->head);
        while (LL)
        {
                if(((compar)(LL->data,dataSought))==0)
                {
                        return LL;
                }
                LL=LL->next;
        }
        return NULL;
}

void *popFront(struct List *list)
// remove from the front of the list
{
        if(isEmptyList(list))
        {
                return NULL;
        }
        struct Node *first = list->head;
        void *stored = first-> data;
        list -> head = first->next;
        free(first);
        return stored;
}

void removeAllNodes(struct List *list)
{
        while(!isEmptyList(list))
        {
                popFront(list);
        }
}

struct Node *addAfter(struct List *list,
            struct Node *prevNode, void *data)
{
        if (prevNode == NULL)
        {
                return addFront(list,data);
        }
        else
        {
                struct Node *new =(struct Node *) malloc(sizeof(struct Node));
                if (new ==NULL)
                {
                        perror("malloc returned null");
                        exit(1);
                }
                new->data=data;
                new->next=prevNode->next;
                prevNode->next=new;
                return new;
        }
}

void reverseList(struct List *list)
{
        struct Node *prv = NULL;
        struct Node *cur = list->head;
        struct Node *next;

        while (cur)
        {
                next=cur->next;
                cur->next=prv;
                prv=cur;
                cur=next;
        }
        list->head =prv;
}
