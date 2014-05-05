/**********************************************************************
 *  utmplib.c - functions to buffer reads from utmp file              *
 *                                                                    *
 *    functions are:                                                  *
 *      utmp_open(filename) - open file                               *
 *          return -1 on error                                        *
 *      utmp_next() - return pointer to next struct                   *
 *          return NULL on eof                                        *
 *      utmp_close()                                                  *
 *                                                                    *
 *    read NRECS per read and then doles them out from the buffer     *
 *                                                                    *
 *    This version use a lots of globals, which I don't like.         *
 **********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <utmp.h>

#define NRECS 16
#define NULLUT ((struct utmp *)NULL)
#define UTSIZE (sizeof(struct utmp))

static char utmpbuf[NRECS * UTSIZE];
static int num_recs;
static int cur_rec;
static int fd_utmp = -1;

int utmp_open(char *filenames)
{
    fd_utmp = open(filenames, O_RDONLY);
    cur_rec = num_recs = 0;
    return fd_utmp;
}

struct utmp * utmp_next()
{
    struct utmp *recp;
    if (fd_utmp == -1)
        return NULLUT;
    if (cur_rec == num_recs && utmp_reload() == 0)
        return NULLUT;

    recp = (struct utmp *) &utmpbuf[cur_rec * UTSIZE];
    cur_rec ++;
    return recp;
}

/* read next bunch of records into buffer */
int utmp_reload()
{
    int amt_read;
    amt_read = read(fd_utmp, utmpbuf, NRECS * UTSIZE);
    num_recs = amt_read / UTSIZE;
    cur_rec = 0;
    return num_recs;
}

int utmp_close()
{
    if (fd_utmp != -1)
        if (close(fd_utmp) == -1)
            perror("close");
    return 0;
}
