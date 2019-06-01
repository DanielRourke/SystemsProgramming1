#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "time.h"


void main(int argc, char *argv[])
{
    int  newpid;
    void child_one_code(int);
    void child_two_code(int);
    void child_three_code(int);
    void parent_code(int);

    for(i = 0; i < 3; i++)
	{
			
			if ( (newpid = fork()) < 0 )
				perror("fork error");
			else if ( newpid == 0 )
				switch (i)
                {
                case: 0
                    child_one_code();
                    break;
                case: 1
                    child_two_code();
                    break;
                case: 2
                    child_three_code();
                    break;
                }
			else
				parent_code(newpid, i);
			
			sleep(1);
	}
}




void parent_code(int childpid, int i)
{
	int wait_rv;		/* return value from wait() */
	int child_status;
	int high_8, low_7, bit_7;

	wait_rv = wait(&child_status);
    switch (i)
    {
    case: 0
        //print highest 
        break;
    case: 1
        //print out word count
        break;
    case: 2
        //print file has been modified
        break;
    }
	// printf("done waiting for %d. Wait returned: %d\n", childpid, wait_rv);

	// high_8 = child_status >> 8;     /* 1111 1111 0000 0000 */
	// low_7  = child_status & 0x7F;   /* 0000 0000 0111 1111 */
	// bit_7  = child_status & 0x80;   /* 0000 0000 1000 0000 */
	// printf("status: exit=%d, sig=%d, core=%d\n", high_8, low_7, bit_7);
}
