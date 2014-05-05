#include <stdio.h>

typedef struct structa_s {
    char c;
    short int s;
} structa_t;

typedef struct structb_s {
    short int s;
    char c;
    int i;
} structb_t;

typedef struct structc_s {
    char c;
    double d;
    int s;
} structc_t;

typedef struct structd_s {
    double d;
    int s;
    char c;
} structd_t;

int main()
{
    printf("sizeof(structa_t) = %lu\n", sizeof(structa_t));
    printf("sizeof(structb_t) = %lu\n", sizeof(structb_t));
    printf("sizeof(structc_t) = %lu\n", sizeof(structc_t));
    printf("sizeof(structd_t) = %lu\n", sizeof(structd_t));

    return 0;
}
