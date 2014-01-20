/**********************************************
 *  who3.c  - who with buffered reads.        *
 *                                            *
 *      compile:                              *
 *          gcc who3.c utmplib.c -o who3.o    *
 **********************************************/
#include <stdio.h>
#include <sys/types.h>
#include <utmp.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>

#define SHOWHOST

int showtime(long);
int show_info(struct utmp * );


int main(int argc, char *argv[])
{
    struct utmp * utbufp;

    if (utmp_open(UTMP_FILE) == -1){
        perror(UTMP_FILE);
        exit(1);
    }
    while ((utbufp = utmp_next()) != ((struct utmp *) NULL))
        show_info(utbufp);
    utmp_close();
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
