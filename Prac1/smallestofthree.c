#include <stdio.h>

int main()
{
    int nums[3]; 
    printf("\n Enter 3 numbers  : ");
    scanf("%d %d %d", &nums[0], &nums[1], &nums[2]);
    int i;
    int smallestNumber = nums[0];
    for ( i = 1 ; i < 3; i++)
    {
	
	if(nums[i] < smallestNumber)
	{
		smallestNumber = nums[i];	 
        }
	 
    }
    printf("The Smallest Number is : %d \n" , smallestNumber);
}
