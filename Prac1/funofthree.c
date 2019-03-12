#include <stdio.h>

main()
{
   int input[3];
   printf("\n Enter 3 Numbers : ");
   scanf("%d %d %d", &input[0], &input[1], &input[2]);
   printf("\n The smallest number is : %d \n", smallest(input));
}

int smallest(int nums[])
{
    int smallestNumber = nums[0] ;
    int i;
    for (i =0 ; i < 3; i++)
    {
	if (nums[i] < smallestNumber)
	{
	   smallestNumber = nums[i];
	}
    }

   return smallestNumber;

}
