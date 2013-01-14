/* Lseek the standard input. */

#include <stdint.h>
#include "apue.h"

int
main(void)
{
    printf("%jd\n", (intmax_t)lseek(STDIN_FILENO, -2, SEEK_SET));
    printf("%jd\n", (intmax_t)lseek(STDIN_FILENO, 3, SEEK_SET));
}
