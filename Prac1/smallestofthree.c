#include <stdio.h>

int main()
{
    int smallestNumber = 99999;
    int enteredNumber;
    int i;
    for ( i = 1 ; i <= 3; i++)
    {
	printf("\n Enter number %d : ", i);
	scanf("%d", &enteredNumber);
	if (enteredNumber < smallestNumber)
	{
	    smallestNumber = enteredNumber;
	}	

    }
    printf("The Smallest Number is : %d \n" , smallestNumber);
}
