#include "stdio.h"
#include "stdlib.h"
#include <fcntl.h>
#include "string.h"

#define BUFFERSIZE      4096
#define COPYMODE        0644


void bad(char *s1, char *s2)
{
	fprintf(stderr, "Error: %s ", s1);
	perror(s2);
	exit(1);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s destination\n", *argv);
		exit(-1);
	}

	int in_fd, out_fd;
	int n_chars;
	char buf[BUFFERSIZE];
	char car[1];
	char word[BUFFERSIZE];
	int letterCount = 0;

	//open files
	if ((in_fd = open(argv[1], O_RDWR)) == -1)
		bad("Cannot open ", argv[1]);

	if ((out_fd = creat("./test.txt", O_RDWR | O_CREAT)) == -1)
		bad("Cannot creat", "./test.txt");



	lseek(in_fd, 0, SEEK_SET);

	//copy original file to temp file with changes
	while ((n_chars = read(in_fd, car, 1)) > 0)
	{
		//add word or punctuation to file
		if (car[0] == ' ' || car[0] == '\n' || letterCount >= BUFFERSIZE - 1 || car[0] == EOF)
		{
			//check if it is a word
			if (letterCount > 0)
			{
				// lseek(out_fd, -(letterCount+ 1) ,SEEK_CUR);

				 //replace execute with run
				if (strncmp(word, "execute", 7) == 0) {
					strcpy(word, "run");
					letterCount = 3;
				}
				//replace study with examine
				else if (strncmp(word, "study", 5) == 0) {
					strcpy(word, "examine");
					letterCount = 7;
				}

				//write word to file
				if (write(out_fd, word, letterCount) != letterCount)
					bad("Write error to ", "./test.txt");
				letterCount = 0;
			}

			//write spaces and punctuation to file
			if (write(out_fd, car, 1) != 1)
				bad("Write error to ", "./test.txt");


		}
		//add a letter to the word
		else
		{
			word[letterCount] = car[0];
			letterCount++;
		}


	}

    //close and open file read from
	printf("closing files");
	if (close(out_fd) == -1)
		bad("Error closing files", "");

	if ((out_fd = open("./test.txt", O_RDWR)) == -1)
		bad("Cannot open ", "./test.txt");

	lseek(in_fd, 0, SEEK_SET);
	lseek(out_fd, 0, SEEK_SET);

    //insert phrase into start of file
    char insert[28] = "this is the updated version";
    if (write(in_fd, insert, 28) != 28)
			bad("Write error to ", argv[1]);

    //copy temp file change to orginal file
	while ((n_chars = read(out_fd, buf, BUFFERSIZE)) > 0)
		if (write(in_fd, buf, n_chars) != n_chars)
			bad("Write error to ", argv[1]);
	if (n_chars == -1)
		bad("Read error from ", "./temp.txt");

	printf("closing files");
	if (close(in_fd) == -1 || close(out_fd) == -1)
		bad("Error closing files", "");



	exit(0);

}


