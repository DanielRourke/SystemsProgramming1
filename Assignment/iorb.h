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

typedef IORB *POINTER;

enum order{Accending , Decending};
void push_front(POINTER *head, priority p, char f[FILLERSIZE]);
void swap(POINTER* A, POINTER* B, POINTER* C);
void print_list(POINTER head);
void pop_front(POINTER* head);
void sort_list_bubble(POINTER* header, int(*calc_pri)(POINTER first, POINTER second));
void build_list(POINTER* head, int size);
int calc_pri_accending(POINTER first, POINTER second);
int test_list(POINTER head, int(*calc_pri)(POINTER, POINTER));