/*******************************
 *  cp2.c - solution for 2.11  *
 *******************************/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFERSIZE 1

int oops(char *, char *);

int main(int argc, char *argv[])
{
    int sourcefd;
    int destfd;
    char buf[BUFFERSIZE];
    int n_chars;

    if (argc != 3){
        fprintf(stderr, "usage: %s source destination \n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], argv[2]) == 0){
        printf("%s: '%s' and '%s' are the same file\n",
                argv[0], argv[1], argv[2]);
        exit(1);
    }

    if ((sourcefd = open(argv[1], O_RDONLY)) == -1)
        perror(argv[1]);

    if ((destfd = creat(argv[2], 644)) == -1)
        perror(argv[2]);

    while ((n_chars = read(sourcefd, buf, BUFFERSIZE)) > 0)
        if (write(destfd, buf, BUFFERSIZE) == -1)
            oops("Write error to ", argv[2]);

    if (n_chars == -1)
        oops("Read error from ", argv[1]);

    if (close(sourcefd) == -1 || close(destfd) == -1)
        oops("Error closing files", "");
    return 0;
}

int oops(char * s1, char * s2)
{
    fprintf(stderr, "Error: %s", s1);
    perror(s2);
    exit(1);
}
