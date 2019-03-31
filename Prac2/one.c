#include "stdio.h"
#include "stdlib.h"

typedef char DATA ;
struct Node
{
    DATA d;
    struct Node * next ;
};


int main()
{
    int i;
    struct Node * head = NULL; 
    for(i = 0; i < 10; i++)
    {
        struct Node * n ;
        n = (struct Node*)malloc(sizeof(struct Node)); 
        n->d = i;
        n->next = head;
        head = n;
    }

    struct Node * it = head;
    while(it != NULL)
    {
        printf(" %d ,", it->d);
        it = it->next;
    }

    return 0;
}
