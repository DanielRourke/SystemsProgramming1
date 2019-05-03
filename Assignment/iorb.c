#include "iorb.h"
#include "assert.h"

void build_list(POINTER* head, int size)
/*Build the list with random filler and base priority*/
{
    assert(size > 0);
    int i;
    for(i = 0; i < size; i++)
    {
        int pri = (rand() % size) % FILLERSIZE + 1;
        int j;
        char str[FILLERSIZE];
        for(j = 0; j < pri ;j++)
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
    assert(p > 0);
    assert(f != NULL);

    POINTER temp = malloc(sizeof(IORB));
    if(temp == NULL)
    {
        perror("out of memory");
    }
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

void print_list(POINTER head)
/*Print the contents of the list. Does not modify the list in any way. */
{

    printf("Start printing the List ...\n ");
    while (head != NULL)
    {
        printf("| %d - %s | \n ", head->base_pri, head->filler );
        head = head->link;
    }
    printf("\n");
}

void delete_list(POINTER *head)
/* Delete the list, i.e. remove all items from the List */
{
    printf("Start deleting the List...\n");

    while (*head != NULL)
    {
        pop_front(head);
    }

    printf("The List in now Empty.\n");
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

void sort_list_bubble(POINTER* header, int(*calc_pri)(POINTER, POINTER))
{
    assert(*header != NULL);
    POINTER* previous;
    POINTER* first;
    POINTER* second;
    int itemsSwaped;
    //loop list until sorted
    do
    {
        previous = header;
        first = &(*previous)->link;
        assert(first != NULL);
        second = &(*first)->link;
        assert(second != NULL);
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
//Swap the position of A and B
{
    //check that h a are not null
    assert(*H != NULL);
    assert((*H)->link != NULL);
    assert(*A != NULL);
    POINTER a = *H;
    POINTER b = *A;
    POINTER c = *B;
    *H = b;
    *A = c;
    *B = a;
}


int calc_pri_accending(POINTER first, POINTER second)
//determines if first priorty is greate that second priority
{

    assert(first->base_pri);
    assert(second->base_pri);
    return first->base_pri > second->base_pri;
}


int test_list(POINTER head, int(*calc_pri)(POINTER, POINTER))
/*Test the contents of the list to see if they are in order. Does not modify the list in any way. */
{
    int ret = 1;
    printf("Start testing the list ...\n ");
    while (head != NULL && head->link != NULL )
    {
        if(calc_pri(head, head->link) == 1) 
        {
            ret = 0;
        }
        head = head->link;
    }
    if (ret  == 1)
        printf("...The List is sorted\n ");
    else if (ret == 0)
        printf("..The List is not sorted\n ");
    else
         printf("...The was an error\n ");

       
    printf("\n");
    return ret;
}

