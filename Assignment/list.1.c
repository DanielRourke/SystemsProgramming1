#include "stdio.h"
#include "stdlib.h"

#define FILLERSIZE


/*Insertion − Adds an element at the beginning of the list.

Deletion − Deletes an element at the beginning of the list.

Display − Displays the complete list.

Search − Searches an element using the given key.

Delete − Deletes an element using the given key.

Swap - swaps the location of Two Values*/

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







typedef int priority;

typedef struct iorb
{
    priority base_pri;
    struct iorb *link;
    char filler[FILLERSIZE];
} IORB;

typedef struct iorb ELEMENT;
typedef ELEMENT *POINTER;

enum order{Accending , Decending};

void push(POINTER *Top, priority p, char f[FILLERSIZE]);
void pop(POINTER *Top);
void swap(POINTER previous);
//void push_string(POINTER *Top, char *string);
void print_stack(POINTER Top);
void delete_stack(POINTER *Top);
void sort(POINTER *head, enum order ord);
void swap2(POINTER prevOfA, POINTER prevOfB);

int main(int argc, char *argv[])
{
    POINTER top;
    POINTER head;
    head =  (POINTER)NULL;
    top = (POINTER)NULL;
    
    priority A = 5;
    priority B = 12;
    priority C = 33;
    priority D = 11;
   // char *C = "12345";
    //	printf("C is %s\n", C);
    push(&top, A, "A");
    push(&top, B, "B");
    push(&top, C, "C");
    push(&top, D, "D");
    print_stack(top);
   // POINTER *Head = &top;
   // sort(Head, Accending);
   
    head = top;
    
    swap2(head, top->link);
    print_stack(top);
    // pop(&top);
    // pop(&top);
    //push_string(&top,C);
    print_stack(top);
    delete_stack(&top);
    print_stack(top);

    return 0;
}

void push(POINTER *Top, priority p, char f[FILLERSIZE])
/* Put item a into the top of the stack */
/* Push a string of characters into a stack. */
{
    POINTER temp;
    temp = malloc(sizeof(ELEMENT));
    temp->base_pri = p;
    // int len = sizeof(f) / sizeof(char);
    // int i;
    // for (i = 0; i < len; i++)////////////////error string empy or not null terminated ?
    // {
    //     temp->filler[i] = f[i];//copies string
    // }
    temp->link = *Top;
    *Top = temp;
    printf("Insert element %d\n", temp->base_pri);
}

void pop(POINTER *Top)
/* Remove the top item */
{
    POINTER Top1 = *Top;
    if (Top != NULL)
    {
        *Top = Top1->link;
        printf("Remove element %d\n", Top1->base_pri);
        free(Top1);
    }
    else
    {
        printf("Empty stack.\n");///////////////error empy or not nulld ?
    }
}

void print_stack(POINTER Top)
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

void delete_stack(POINTER *Top)
/* Delete the stack, i.e. remove all items from the stack */
{
    printf("Start deleting the stack...\n");

    while (*Top != NULL)///////////////error empy or not nulld ?
    {
        pop(Top);
    }
}

void swap(POINTER previous)
{
    /*Swap the location of two middle list items*/
    /*Pre condition A->B->C->D*/
    /*Post condition A->C->B->D*/
    POINTER B = previous->link;
    POINTER C = previous->link->link;
    POINTER D = previous->link->link->link;

    //A points to C
    previous->link = C;
    //Change to C
    previous = C;
    //C points to B
    previous->link = B;
    //Change to B
    previous = B;
    //B points to D
    previous->link = D;
}

void sort(POINTER *head, enum order ord)
{
    int a;
    int b;
    int swapsMade;
    POINTER current  = *head;
    printf("Start sorting the stack...\n");
    while(current->link != NULL)
    {

        a =  current->base_pri;
        b =  current->link->base_pri;
          printf(" a %d b %d,", a,b);
        if(a > b)
        {

            printf(" %d is bigger than %d,", a,b);
            swap(current);
        }
        current = current->link;
    }
     printf("\n");
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
// void push_string(POINTER *Top,char *string)
// /* Push a string of characters into a stack. */
// 	{
// 		printf("Start inserting the string ...\n");
// 		while(*string != '\0')
// 		{
// 				push(Top, *string);
// 				string++;
// 		}

// 		/*insert you code here */
// 	}




/* Head is a pointer to  and struct

top is a stuct object with pointer

so POINTER head -> top
top->link points to next

so we compare
head 
and top->next



*/