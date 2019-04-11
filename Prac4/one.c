#include "stdio.h"
#include "stdlib.h"
#include  <fcntl.h>
#include  <unistd.h>


/*
    Experiment with opening the same file several times. Write a program that does the
    following:

    (a) Open a file for reading, then
    (b) Open the same file for writing, then
    (c) Open the same file for reading.
    You should now have three file descriptors. The program should then
    (d) read 50 bytes using the 1st fd and print what you get
    (e) Write the string “testing 1 2 3 ...” using the 2nd fd
    (f) Read 50 bytes using the 3rd fd and print what you get.
*/


int main(int argc, char *argv[])
{
    int fd0, fd1, fd2 , returnCode;
    ssize_t nread;
    char buffer[1024];

    fd0=open("test.txt", O_RDONLY);
    if(fd0 == -1)
    {
        printf("Error opening file test");
        return fd0;
    }

    fd1=open("test.txt", O_WRONLY);
    if(fd1 == -1)
    {
        printf("Error opening file test");
        return fd1;
    }

    
    fd1=open("test.txt", O_RDONLY);
    if(fd2 == -1)
    {
        printf("Error opening file test");
        return fd2;
    }
    

    nread=read(fd0, buffer, 50);
    returnCode
    



   return 0;
}

