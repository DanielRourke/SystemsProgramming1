#include <stdio.h>

main(int argc,char *argv[])
{
	while(argc--)
                printf("%s\n", *argv++);	

} 
