/*
 *  should support:
 *      acc smith
 *      acc smith -w wtmp.sample
 */
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <utmp.h>
#include <string.h>
#include <time.h>
#include "utmplib.h"


struct utmp * find_corrsponding_end(char *, char *, off_t);

int main(int argc, char *argv[])
{
    int index;
    int opt;
    int utmp_fd;
    char *wtmpfile = WTMP_FILE;
    char username[UT_NAMESIZE];
    char id[4];
    short type;
    time_t start_time, end_time, total_time;
    struct utmp *utbufp, *utbufp2;
    off_t currpos1, currpos2;

    opterr = 0;

    printf("%s\n", WTMP_FILE);
    while ((opt = getopt(argc, argv, "w:")) != -1){
        printf("opind = %d\n", optind);
        switch (opt){
            case 'w':
                wtmpfile = optarg;
                break;
            case '?':
                if (optopt == 'w')
                    fprintf(stderr,
                            "Option -%c requires an argument.\n",
                            optopt);
                else if (isprint(optopt))
                    fprintf(stderr,
                            "Unknown option `-%c'.\n",
                            optopt);
                else
                    fprintf(stderr,
                            "Unknown option character `\\x%x'\n",
                            optopt);
                return 1;
            default:
                abort();
        }
    }

    strncpy(username, argv[optind], UT_NAMESIZE);

    printf("wtmpfile is %s\n", wtmpfile);
    printf("username is %s\n", username);

    if ((utmp_fd = utmp_open(wtmpfile)) == -1){
        perror(wtmpfile);
        exit(1);
    }

    currpos1 = 0;
    while ((utbufp = utmp_next(utmp_fd, &currpos1)) != ((struct utmp*) NULL)){
        printf("currpos1 is %d\n\n", (int)currpos1);
        if (strcmp(username, utbufp->ut_user) == 0){
            strncpy(id, utbufp->ut_id, 4);
            type = utbufp->ut_type;
            start_time = utbufp->ut_time;
            if (type == USER_PROCESS){
                /*printf("id: %s, type: %d, start_time: %lu\n", id, type, start_time);*/
                currpos2 = lseek(utmp_fd, 0, SEEK_CUR);
                /*printf("currpos2 is %d\n\n", (int)currpos2);*/
                /*utbufp2 = find_corrsponding_end(id, wtmpfile, currpos2);*/
                /*if (utbufp2 == (struct utmp*)NULL){*/
                    /*time(&end_time);*/
                /*} else {*/
                    /*end_time = utbufp2->ut_time;*/
                /*}*/
                /*total_time += end_time - start_time;*/
                /*printf("start_time: %lu, end_timd: %lu, total_time: %lu\n",*/
                        /*start_time, end_time, total_time);*/
            }
        }
    }

    utmp_close(utmp_fd);
    return 0;
}

struct utmp * find_corrsponding_end(char *id, char *wtmpfile, off_t currpos)
{
    int utmp_fd;
    struct utmp *utbufp;

    if ((utmp_fd = utmp_open(wtmpfile)) == -1){
        perror(wtmpfile);
        exit(1);
    }

    while ((utbufp = utmp_next(utmp_fd, &currpos)) != ((struct utmp*) NULL)){
        if (strcmp(id, utbufp->ut_id) == 0)
            utmp_close(utmp_fd);
            return utbufp;
    }

    utmp_close(utmp_fd);
    return ((struct utmp *)NULL);
}
