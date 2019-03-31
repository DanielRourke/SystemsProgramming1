#include "stdio.h"
#include "stdlib.h"

typedef char DATA ;
struct Node
{
    DATA d;
    struct Node * next ;
};

struct Node * reverse(struct Node * h);

int main()
{
    int i;

    struct Node * previous; 
    previous = (struct Node*)malloc(sizeof(struct Node)); 
    struct Node * head = previous; 
    for(i = 0; i < 11; i++)
    {
        struct Node * next;
        next = (struct Node*)malloc(sizeof(struct Node));
        next->next = NULL;
        previous->d = i;
        previous->next = next;
        previous = next;
    }

    struct Node * it = head;
    while(it->next != NULL)
    {
        printf(" %d ,", it->d);
        it = it->next;
    }

    head = reverse(head);

    it = head;
    while(it->next != NULL)
    {
        printf(" %d ,", it->d);
        it = it->next;
    }

    return 0;
}

struct Node *reverse(struct Node * h)
{

    struct Node * head = NULL; 

    while(h->next != NULL)
    {
        struct Node * n ;
        n = (struct Node*)malloc(sizeof(struct Node)); 
        n->d = h->d;
        n->next = head;
        head = n;
        h = h->next;
    }


   return head;
}
