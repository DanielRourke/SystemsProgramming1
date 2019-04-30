#include "stdio.h"
#include "stdlib.h"

#define FILLERSIZE 

typedef int priority;

typedef struct iorb
{
    priority base_pri;
    struct iorb *link;
    char filler[FILLERSIZE];
}IORB;

typedef struct iorb IORB;
typedef IORB *POINTER;


enum order{Accending , Decending};

void push_back(POINTER Back, int p, char f[10]);
void push_front(POINTER *Head, priority p, char f[10]);
void swap(POINTER previous);
void sortBubble(POINTER Head);
void sort(POINTER *head, enum order ord);
void print_list(POINTER Top);

int main(int argc, char *argv[])
{
    POINTER Head;
    Head = (POINTER)NULL;
    priority A = 5;
    priority B = 12;
    priority C = 33;
    priority D = 11;
    push_front(&Head, A, "A");
    push_front(&Head, B , "B");
    push_front(&Head, C , "C");
   // print_list(Head);


    return 1;
}



void push_front(POINTER *Head, priority p, char f[10])
/* Put item a into the front of the list */
/* Push a string of characters into a list. */
{
    POINTER temp;
    temp->base_pri = p;
    // int len = sizeof(*f) / sizeof(char);
    // int i;
    // for (i = 0; i < len; i++)
    // {
    //     temp->filler[i] = f[i];//copies string
    // }
    temp->link = *Head;
    *Head = temp;
    printf("Insert element front %d %a\n", temp->base_pri , temp->link);
}

void push_back(POINTER Back, priority p, char f[10])
/* Put item a into the front of the list */
/* Push a string of characters into a list. */
{
    POINTER temp;
    temp = malloc(sizeof(IORB));
    temp->base_pri = p;
    // int len = sizeof(f) / sizeof(char);
    // int i;
    // for (i = 0; i < len; i++)
    // {
    //     temp->filler[i] = f[i];//copies string
    // }
    temp->link = NULL;
    Back->link = temp;
    printf("Insert element back %d\n", temp->base_pri);
}

void print_list(POINTER Top)
/*Print the contents of the stack. Do not modify the stack in any way. */
{

    printf("Start printing the stack ...\n");
    while (Top != NULL)///////////////error empy or not nulld ?
    {
        printf(" %d ,", Top->base_pri);
        Top = Top->link;
    }
    printf("\n");
}