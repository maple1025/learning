/************************************
 *  Demonstrate how to use sizeof.  *
 ************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM_ELEM(x) (sizeof(x) / sizeof(*(x)))


// When sizeof is applied to the name of a static array (not allocated through
// malloc), the result is the size in bytes of the whole array. This is one of
// the few exceptions to the rule that the name of an array is converted to a
// pointer to the first element of the array, and is possible just because the
// actual array size is fixed and known at compile time, when sizeof operator
// is evaluated.
int test_static_array()
{
    char buffer[10];

    printf("sizeof(buffer) = %zu, sizeof(buffer[0]) = %zu \n",
           sizeof(buffer), sizeof(buffer[0]));

    strncpy(buffer, "segsegegdffdfdfd", sizeof(buffer) - sizeof(buffer[0]));
    return 0;
}


// C99 adds support for flexible array members to structure. This form of array
// is allowed as the last element in structures only. For a structure named s
// containing a flexible array named a, sizeof is equivalent to offsetof(s, a)
int test_flexible_array_member()
{
    struct flexarray1
    {
        char val;
        int array[];    // Flexible array member; must be the last element.
    };

    struct flexarray2
    {
        char val;
        int array[2];
    };

    struct flexarray3
    {
        char val;
    };

    // 4, in this case, sizeof return the size of the structure, including any
    // padding, but without any storage for the flexible array. It's 4 not 1
    // becauce of padding.
    printf("sizeof(struct flexarray1) = %zu\n", sizeof(struct flexarray1));

    // 12
    printf("sizeof(struct flexarray2) = %zu\n", sizeof(struct flexarray2));
    // 1
    printf("sizeof(struct flexarray3) = %zu\n", sizeof(struct flexarray3));

    return 0;
}


// C99 allows variable length arrays where the length is specified at runtime.
// In such cases, the sizeof is evaluated in part at runtime to determine the
// storage occupied by the array.
int test_variable_length_array(int n)
{
    char b[n+3];
    printf("sizeof(b) = %zu\n", sizeof(b));
    return 0;
}


// Pointer returned by malloc is actually a pointer, not real array.
int test_dynamic_array()
{
    int *pi = malloc(sizeof(int) * 10);
    int *pc = malloc(sizeof(char) * 10);

    printf("sizeof(pi) = %zu\n", sizeof(pi));
    printf("sizeof(pc) = %zu\n", sizeof(pc));
    printf("sizeof(int) = %zu\n", sizeof(int));

    return 0;
}


// And array passed to function will decay into pointer, so sizeof will not
// give the array length of the original array. That's why the main in standard
// is:
//      int main(int argc, char** argv);
// Passing the length of argv as a parameter.
int test_array_parameter(char* a)
{
    printf("sizeof(a) = %zu\n", sizeof(a));

    return 0;
}


int main(int argc, char *argv[])
{
    char c;
    printf("sizeof(c) = %zu byte(s), sizeof(int) = %zu byte(s)\n",
           sizeof(c), sizeof(int));

    test_static_array();
    test_flexible_array_member();
    test_variable_length_array(3);
    test_dynamic_array();

    char a[10];
    test_array_parameter(a);
    printf("number of element in a is %zu\n", NUM_ELEM(a));
    return 0;
}
