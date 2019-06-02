#include "stdio.h"
#include "stdlib.h"

#define studentCount 10

int main(int argc, char *argv[])
{
    //local variable
    char buffer[4096];
    int input;
    int max = 0;
    int i;
    sleep(1);
    //get student scores from user
    for (i = 0; i < studentCount ; i++)
    {
        printf("\n Enter a score between 1 and 100: ");
        if(fgets(buffer, sizeof(buffer), stdin))
        {
            //flush buffer
            rewind(stdin);
            //validate user input is a number
           if(input = atol(buffer))
           {
               //validate input is in range
               if(input <= 100 && input > 0){
                    if(input > max){
                        max = input;   
                    }
               }
               else
               {
                    printf("score not within bounds");
                    i--;
               }

           }
           
            else
            {
                printf("Invalid Input not a number");
                i--;
            }

        }
        //report error
        else
        {
            perror("Invalid Input");
            return -1;
        }
           
    }
    //Print result
    printf("Highest Score is: %d \n" ,max);
    exit(max);
}