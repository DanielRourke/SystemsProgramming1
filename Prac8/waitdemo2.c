/*
4. How do we create a new process? How can a process determine if it is the parent process

A fork() system call creates a child process. The child
process begins its life not at the start of main but at the return
from fork
• We need to distinguish the new process from the original one.
In the child process, fork() returns 0. In the parent process,
fork() returns a positive value 

5. Describe how a parent process can communicate with its child process. (1%)
• A process sends a signal to another process by using the kill
system call
• when the child calls exit, the kernel wakes up the parent and
delivers the value the child passed to exit
 */





#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "time.h"

#define	DELAY	5

void main(int argc, char *argv[])
{
	srand(time(0));
	int  newpid;
	void child_code(int), parent_code(int);

	if (argc != 2 )
	{
		printf("Usage prac8.c followed by postative number \n");
	}
	
	printf("before: mypid is %d\n", getpid());
	int i;
	for(i = 0; i < atoi(argv[1]); i++)
	{
			int delay = rand() % DELAY + 1;
			if ( (newpid = fork()) == -1 )
				perror("fork");
			else if ( newpid == 0 )
				child_code(delay);
			else
				parent_code(newpid);
			
			sleep(1);
	}

}
/*
 * new process takes a nap and then exits
 */
void child_code(int delay)
{
	printf("child %d here. will sleep for %d seconds\n", getpid(), delay);
	sleep(delay);
	printf("child done. about to exit\n");
	exit(17);
}
/*
 * parent waits for child then prints a message
 */
void parent_code(int childpid)
{
	int wait_rv;		/* return value from wait() */
	int child_status;
	int high_8, low_7, bit_7;

	wait_rv = wait(&child_status);
	printf("done waiting for %d. Wait returned: %d\n", childpid, wait_rv);

	high_8 = child_status >> 8;     /* 1111 1111 0000 0000 */
	low_7  = child_status & 0x7F;   /* 0000 0000 0111 1111 */
	bit_7  = child_status & 0x80;   /* 0000 0000 1000 0000 */
	printf("status: exit=%d, sig=%d, core=%d\n", high_8, low_7, bit_7);
}
