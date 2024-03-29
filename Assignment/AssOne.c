#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define FILLERSIZE 100

typedef int priority;

typedef struct iorb
{
    priority base_pri;
    struct iorb *link;
    char filler[FILLERSIZE];
}IORB;

typedef IORB *POINTER;


enum order{Accending , Decending};
void push_front(POINTER *head, priority p, char f[FILLERSIZE]);
void swap(POINTER* A, POINTER* B, POINTER* C);
void print_list(POINTER head);
void pop_front(POINTER* head);
void sort_list_bubble(POINTER* header, int(*calc_pri)(POINTER first, POINTER second));
void build_list(POINTER* head, int size);
int calc_pri_accending(POINTER first, POINTER second);

int main(int argc, char *argv[])
{

    //check user input 
    srand(time(0));
    POINTER Head;
    Head = (POINTER) 0;
    build_list(&Head, 20);
    print_list(Head);
    sort_list_bubble(&Head , calc_pri_accending );
    print_list(Head);

    return 1;
}

void build_list(POINTER* head, int size)
/*Build the list with random filler and base priority*/
{
    int i;
    for(i = 0; i < size; i++)
    {
        int pri = rand() % size +1;
        int j;
        char str[FILLERSIZE];
        for(j =0; j < pri ;j++)
        {
            str[j] = 'A' +  rand()% 26;
        }
        str[pri] = '\0';
        push_front(head, pri , str);
    }
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
    //*temp->filler = *f;
    temp->link = *head;
    *head = temp;
    printf("Insert element front %d %p %s\n", temp->base_pri ,
    temp->link, temp->filler);
}

void print_list(POINTER head)
/*Print the contents of the list. Does not modify the list in any way. */
{

    printf("Start printing the stack ...\n ");
    while (head != NULL)
    {
        printf("| %d - %s | \n ", head->base_pri, head->filler );
        head = head->link;
    }
    printf("\n");
}

void delete_list(POINTER *head)
/* Delete the stack, i.e. remove all items from the stack */
{
    //check for error
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
    ///check errors 
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

void sort_list_bubble(POINTER* header, int(*calc_pri)(POINTER, POINTER))
{
    //validate the list size is atleast 2
    POINTER* previous;
    POINTER* first;
    POINTER* second;
    int itemsSwaped;
    //loop list until sorted
    do
    {
        previous = header;
        first = &(*previous)->link;
        second = &(*first)->link;
        itemsSwaped = 0;
        //loop through list
        while((*first) != NULL)
        {
            first = &(*previous)->link;
            second = &(*first)->link;

            if(calc_pri(*previous, *first))
            {
                swap(previous,first,second);
                previous = second;
                itemsSwaped +=1;
         
            }
            else
            {
                previous = first;
            }

            first = &(*previous)->link;
            second = &(*first)->link;
        }
    }while(itemsSwaped != 0);
}

void swap(POINTER* H, POINTER* A, POINTER* B)
{
    //check that h a are not null and b link is not null
    POINTER a = *H;
    POINTER b = *A;
    POINTER c = *B;
    *H = b;
    *A = c;
    *B = a;
}


int calc_pri_accending(POINTER first, POINTER second)
{
    return first->base_pri > second->base_pri;
}

