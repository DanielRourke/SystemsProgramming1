#include "stdio.h"
#include "stdlib.h"

int fact(int);

int main(int argc, char *argv[])
{
    printf("%d! = %d", atoi(argv[1]),fact(atoi(argv[1])));
    return 0;
}

int fact(int n)
{
    if (n <= 1) 
        return n;
    else
        return n = n * fact(n-1);
} 