#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <utmp.h>
#include <sys/types.h>
#include <unistd.h>

#define NRECS 1
#define NULLUT ((struct utmp *)NULL)
#define UTSIZE (sizeof(struct utmp))

int utmp_open(char *);
struct utmp * utmp_next(int, off_t *);
int utmp_reload(int, off_t *);
int utmp_close(int);
