#include <stdio.h>

main(int argc, char *argv[])
{

   //printf("%d", atoi(argv[1]));
   
    printf("\n %d! = %d", atoi(argv[1]),atoi(fact(argv[1])));

}

int fact(int n)
{
    if (n > 0)
	return n * fact(n - 1);
    else
	return n;
} 
