/** cp1.c
 *     version 1 of cp - uses read and write 
 *     with tunable buffer size
 *
 *     usage: cp1 src dest
 */
#include        <stdio.h>
#include        "stdlib.h"
#include        <unistd.h>
#include        <fcntl.h>

#define BUFFERSIZE      4096
#define COPYMODE        0644

void oops(char *, char *);
main(int ac, char *av[])
{
    int     in_fd, out_fd, n_chars;
    char    buf[BUFFERSIZE];

         /* open files   */

    if ( (in_fd=open("afile.1.txt", O_RDONLY)) == -1 )
        oops("Cannot open ", "afile.1.txt");

    if ( (out_fd=creat( "afile.txt", COPYMODE)) == -1 )
        oops( "Cannot creat", "afile.txt");

                                                /* copy files   */
while ( (n_chars = read(in_fd , buf, BUFFERSIZE)) > 0 )
        if ( write( out_fd, buf, n_chars ) != n_chars )
                oops("Write error to ","afile.txt");
        if ( n_chars == -1 )
                oops("Read error from ","afile.1.txt");

                                                /* close files  */

 if ( close(in_fd) == -1 || close(out_fd) == -1 )
                oops("Error closing files","");
}

void oops(char *s1, char *s2)
{
        fprintf(stderr,"Error: %s ", s1);
        perror(s2);
        exit(1);
}
