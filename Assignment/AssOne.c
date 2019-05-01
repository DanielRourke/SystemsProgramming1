#include "stdio.h"
#include "stdlib.h"

#define FILLERSIZE 100

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

//void push_back(POINTER Back, int p, char f[FILLERSIZE]);
void push_front(POINTER *head, priority p, char f[FILLERSIZE]);
void swap(POINTER* A, POINTER* B, POINTER* C);
void sortBubble(POINTER head);
void sort(POINTER *head, enum order ord);
void print_list(POINTER head);
void pop_front(POINTER* head);
void swap2(POINTER prevOfA, POINTER prevOfB);
void sort_list(POINTER head);


int main(int argc, char *argv[])
{
    POINTER Head;
    Head = (POINTER) 0;
    priority A = 5;
    priority B = 12;
    priority C = 33;
    priority D = 11;
    push_front(&Head, A, "A");
    push_front(&Head, B, "B");
    push_front(&Head, C, "C");
    push_front(&Head, D, "D");
    sort_list(Head);
    print_list(Head);
   // swap(&Head , &Head->link, &Head->link->link);
   // sort(&Head, Accending);
    print_list(Head);
    return 1;
}



void push_front(POINTER* head, priority p, char f[FILLERSIZE])
/* Put item a into the front of the list */
/* Push a string of characters into a list. */
{
    
    POINTER temp = malloc(sizeof(IORB));
    temp->base_pri = p;
    //when you pass an char array it becomes char array pointer to first point
    int i = 0;
    while(*f != '\0')
    {
       temp->filler[i] = *f;
        i++;
        *f++;
    } 
    temp->filler[i]= '\0';
    temp->link = *head;
    *head = temp;
    printf("Insert element front %d %p %s\n", temp->base_pri ,
    temp->link, temp->filler);
}

// void push_back(POINTER Back, priority p, char f[FILLERSIZE])
// /* Put item a into the front of the list */
// /* Push a string of characters into a list. */
// {
//     POINTER temp;
//     temp = malloc(sizeof(IORB));
//     temp->base_pri = p;
//     // int len = sizeof(f) / sizeof(char);
//     // int i;
//     // for (i = 0; i < len; i++)
//     // {
//     //     temp->filler[i] = f[i];//copies string
//     // }
//     temp->link = NULL;
//     Back->link = temp;
//     printf("Insert element back %d\n", temp->base_pri);
// }

void print_list(POINTER head)
/*Print the contents of the stack. Do not modify the stack in any way. */
{

    printf("Start printing the stack ...\n");
    while (head != NULL)///////////////error empy or not nulld ?
    {
        printf(" %d ,", head->base_pri);
        head = head->link;
    }
    printf("\n");
}

void delete_list(POINTER *head)
/* Delete the stack, i.e. remove all items from the stack */
{
    printf("Start deleting the stack...\n");

    while (*head != NULL)
    {
        pop_front(head);
    }

    printf("The Stack in now Empty.\n");
}

void pop_front(POINTER* head)
/* Remove the top item */
{
    POINTER current = *head;
    if (*head != NULL)
    {
        *head = current->link;
        printf("Remove element %d\n", current->base_pri);
        free(current);
    }
    else
    {
        printf("Empty stack.\n");
    }
}

// void swap(POINTER previous)
// {
//     /*Swap the location of two middle list items*/
//     /*Pre condition A->B->C->D*/
//     /*Post condition A->C->B->D*/
//     POINTER B = previous->link;
//     POINTER C = previous->link->link;
//     POINTER D = previous->link->link->link;

//     //A points to C
//     previous->link = C;
//     //Change to C
//     previous = C;
//     //C points to B
//     previous->link = B;
//     //Change to B
//     previous = B;
//     //B points to D
//     previous->link = D;
// }


void sort_list(POINTER head)
/*Print the contents of the stack. Do not modify the stack in any way. */
{
    
   
    POINTER* first = &head;
    POINTER* second = &head->link;
    POINTER* third = &head->link->link;
 
    swap(&head, &head->link, &head->link->link);

    
}


void swap(POINTER* H, POINTER* A, POINTER* B)
{
   
    POINTER a = *H;
    POINTER b = *A;
    POINTER c = *B;
    // printf(" a %p b %p c %p, \n", *H, *A, *B);
    // printf(" a %p b %p c %p,\n", a, b, c);
    // printf(" a %s b %s c %s,\n", a->filler, b->filler, c->filler);
    // printf(" a %p b %p c %p,\n", a->link, b->link, c->link);
 
    *H = b;
    *A = c;
    *B = a;

    // printf(" a %p b %p c %p, \n", *H, *A, *B);
    // printf(" a %p b %p c %p,\n", a, b, c);
    // printf(" a %s b %s c %s,\n", a->filler, b->filler, c->filler);
    // printf(" a %p b %p c %p,\n", a->link, b->link, c->link);
    //*A points to *C
    //*C link points to *B
    //*B link points to *C-Link

    

   // POINTER tempPtr = *prevOfA;
  //  prevOfA = prevOfB;
 //   *prevOfB = tempPtr;
  //  printf("\n a %p b %p,", prevOfA,prevOfB);
}


void swap2(POINTER prevOfA, POINTER prevOfB)
{
    /*Swap the location of two middle list items*/
    /*Pre condition A->B->C->D*/
    /*Post condition A->C->B->D*/

  /*Pseudo Code for Swap
take the address of the two list items that point to the items
that are to be swaped
if you want to swap B and F 
where A points to B and  E Points to F
Send A and E to function

    

make A.link point to F
make E.link point to B
make temp pointer = B.link
make B.link = F.link
make F.link = Temp;
*/
    printf("\n a %p b %p,", prevOfA,prevOfB);
    POINTER tempPtr = prevOfA;
    prevOfA = prevOfB;
    prevOfB = tempPtr;
    printf("\n a %p b %p,", prevOfA,prevOfB);

    printf("\n a %p b %p,", prevOfA->link,prevOfB->link);
    printf("\n a %d b %d,", prevOfA->link->base_pri,prevOfB->link->base_pri);
    tempPtr = prevOfA->link;
    prevOfA->link = prevOfB->link;
    prevOfB->link = tempPtr;
    printf("\n a %p b %p,", prevOfA->link,prevOfB->link);
    printf("\n a %d b %d,", prevOfA->link->base_pri,prevOfB->link->base_pri);
    printf("\n a %p b %p,", prevOfB->link, tempPtr);
}

void sort(POINTER* head, enum order ord)
{
  //  int a;
   // int b;
    int swapsMade;

    
    // POINTER prev = *head;
    // POINTER* first = head
    // POINTER* second = &prev->link;
    // POINTER* third = &prev->link->link;

    POINTER* first = head;
    POINTER a = *first;
    
    POINTER* second = &a->link;
    POINTER b = *second;
    
    POINTER* third =  &b->link;
    POINTER c = *third;


    swapsMade = 0;


    //while(c != NULL)
    {



        if(a->base_pri < b->base_pri)
        {
                    printf("first points %p\n", *first);
                    printf("secomd points %p\n", *second);
                    printf("sthid points %p\n", *third);
            swap(first, second, third);
             printf("first points %p\n", *first);
            printf("secomd points %p\n", *second);
            printf("sthid points %p\n", *third);
            printf("swap");
        }
    }

    //     +
        
        
    //    // first = &a->link;
    //     second = &b->link;
    //     third = &c->link;
    //     a = *first;
    //     b = *second;
    //     c = *third;

    // }
   
  

    // printf("first points %s\n", a->filler);
    // printf("secomd points %s\n", b->filler);
    // printf("sthid points %s\n", c->filler);
   // swap(first, second, third);

    
    // POINTER* previous = head;
    //  printf("previous points %p\n", previous);
    //   printf("previous points %p\n", *head );
    // POINTER first;
    // POINTER second;
    // first  = *previous;
    // second =  first->link;
    // printf("previous points %p\n", previous );
    // printf("first points %p\n", first );
    // printf("second points %p\n", second );

    // do{

    //     printf("previous points %s\n", previous->filler );
    //     printf("first points %s\n", first->filler );
    //     printf("second points %s\n", second->filler );
    //     swapsMade = 0;
    //     printf("Start sorting the list...\n");
    //    while(previous->link != NULL)
    //     {
    //         first  = previous;
    //         second =  first->link;
    //         a =  first->base_pri;
    //         b =  second->base_pri;
    //         print_list(*head);
    //         printf(" a %d b %d,", a,b);
    //         if(a > b)
    //         {
    //             printf(" %d is bigger than %d,", a,b);
    //             swap(first,second);
    //             swapsMade++;
    //         }
    //         previous = previous->link;

    //         print_list(*head);
            
    //         printf("previous points %s\n", previous->filler );
    //     }
    // }while(swapsMade != 0);
    
    // printf("\n");
}