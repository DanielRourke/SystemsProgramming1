#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "time.h"


void main(int argc, char *argv[])
{
    /* check args   */
    if ( argc != 3 ){
        fprintf( stderr, "usage: %s file1 file2\n", *argv);
        exit(1);
    }

    //set local variables
    int  newpid;
    void parent_code(int);

    //fork the first task
	if ( (newpid = fork()) < 0 )
			perror("fork error");
	else if ( newpid == 0 ){
        execv("./one", NULL );
    }
    else
    {   //fork the second task
        if ( (newpid = fork()) < 0 )
                perror("fork error");
        else if ( newpid == 0 )
                execl("/usr/bin/wc","wc","-w", argv[1], NULL );
        else{
                    //fork the third task
                    if ( (newpid = fork()) < 0 )
                            perror("fork error");
                    else if ( newpid == 0 )
                            execl("./three","./three", argv[2], NULL );
                    else{
                        parent_code(newpid);
                        parent_code(newpid);
                        parent_code(newpid);
                    }
        }
    }
}




void parent_code(int childpid)
{
            int wait_rv;		/* return value from wait() */
            int child_status;
            int high_8, low_7, bit_7;

            wait_rv = wait(&child_status);

            high_8 = child_status >> 8;     /* 1111 1111 0000 0000 */
            low_7  = child_status & 0x7F;   /* 0000 0000 0111 1111 */
            bit_7  = child_status & 0x80;   /* 0000 0000 1000 0000 */
            printf("status: exit=%d, sig=%d, core=%d\n", high_8, low_7, bit_7);
}
