/******************************************************
 *  who2.c - read /etc/utmp and list info therein     *
 *         - suppresses empty records                 *
 *         - format time nicely                       *
 ******************************************************/
#include <stdio.h>
#include <unistd.h>
#include <utmp.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>

#define SHOWHOST

int showtime(long);
int show_info(struct utmp * );

int main(int argc, char *argv[])
{
    struct utmp utbuf;
    int utmpfd;

    if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1){
        perror(UTMP_FILE);
        exit(1);
    }

    while( read(utmpfd, &utbuf, sizeof(utbuf)) == sizeof(utbuf))
        show_info(&utbuf);

    close(utmpfd);
    return 0;
}

/***************************************************
 *  show_info()                                    *
 *      display the contents of the utmp struct    *
 *      in human readable form                     *
 *      display nothing if record has no user name *
 **************************************************/
int show_info(struct utmp *utbuf)
{
    if (utbuf->ut_type != USER_PROCESS)
        return;

    printf("%-8.8s", utbuf->ut_name);
    printf(" ");
    printf("%-8.8s", utbuf->ut_line);
    printf(" ");
    showtime(utbuf->ut_time);
#ifdef SHOWHOST
    if(utbuf->ut_host[0] != '\0')
        printf("( %s )", utbuf->ut_host);
#endif
    printf("\n");
    return 0;
}

/****************************************************************************
 *  showtime                                                                *
 *         display time in format fit for human consumption                 *
 *         use ctime to build a string then picks parts out of it           *
 *         Note: %12.12s prints a string 12 chars wide and LIMITS it to 12  *
 *         chars                                                            *
 ****************************************************************************/
int showtime(long timeval)
{
     char *cp;
     cp = ctime(&timeval);
     printf("%12.12s", cp+4);
     return 0;
}
