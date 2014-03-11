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
#include "utmplib.h"

static char utmpbuf[NRECS * UTSIZE];
static int num_recs;
static int cur_rec;

int utmp_open(char *filenames)
{
    int fd_utmp = -1;
    fd_utmp = open(filenames, O_RDONLY);
    cur_rec = num_recs = 0;
    return fd_utmp;
}

struct utmp * utmp_next(int fd_utmp, off_t *currposp)
{
    struct utmp *recp;
    if (fd_utmp == -1)
        return NULLUT;
    if (cur_rec == num_recs && utmp_reload(fd_utmp, currposp) == 0)
        return NULLUT;

    recp = (struct utmp *) &utmpbuf[cur_rec * UTSIZE];
    cur_rec ++;
    return recp;
}

/* read next bunch of records into buffer */
int utmp_reload(int fd_utmp, off_t *currposp)
{
    int amt_read;
    lseek(fd_utmp, *currposp, SEEK_SET);
    amt_read = read(fd_utmp, utmpbuf, NRECS * UTSIZE);
    *currposp = lseek(fd_utmp, 0, SEEK_CUR);
    num_recs = amt_read / UTSIZE;
    cur_rec = 0;
    return num_recs;
}

int utmp_close(int fd_utmp)
{
    if (fd_utmp != -1)
        if (close(fd_utmp) == -1)
            perror("close");
    return 0;
}
