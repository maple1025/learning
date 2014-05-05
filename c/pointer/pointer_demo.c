/*
 * demo code from wiki book:
 *      http://en.wikibooks.org/wiki/C_Programming/Pointers_and_arrays
 *
 * 1. Declaring pointers
 * 2. Assigning values to pointer
 * 3. Pointer dereferencing
 * 4. Pointers and arrays
 * 5. Pointers in function arguments
 * 6. Pointers and text strings
 * 7. Pointers to functions
 * 8. Practical use of function pointers in C
 * 9. Examples of pointer constructs
 *
 */
#include <stdlib.h>
#include <stdio.h>

struct mix {
    int a;
    float b;
};

int main(int argc, char *argv[])
{
    int *pa;
    struct mix *pm;
    struct mix *pma;
    int a;
    struct mix m;

    pa = &a;
    pm = &m;
    pma = malloc(sizeof(struct mix) * 10);

    int c, d;
    int *pj;

    c = 10;
    pj = &c; // pj pointer to c
    d = *pj; // d assigned to the value pointer by pj, that is c
    printf("c = %d, d = %d\n", c, d);
    pj = &d; // pj pointer to d
    *pj = 12; // the value pj pointer to is 12, that is d
    printf("c = %d, d = %d\n", c, d);

    return 0;
}
