/****************************************************************
 *  Demo code shows how to use bit fields.                      *
 *  http://www.tutorialspoint.com/cprogramming/c_bit_fields.htm *
 ****************************************************************/

#include <stdio.h>
#include <string.h>

/* define a simple structure */
struct{
    unsigned int widthValidated;
    unsigned int heightValidated;
} status1;

/* define a structure with bit fields */
struct{
    unsigned int widthValidated : 1;
    unsigned int heightValidated : 1;
} status2;

struct{
    unsigned int a : 1;
    unsigned int b : 31;
} status3;

struct{
    unsigned int a : 1;
    unsigned int b : 32;
} status4;

struct{
    unsigned int age : 3;
} Age;

int main()
{
    printf("Memory size occupied by status1: %d\n", sizeof(status1)); // 8
    printf("Memory size occupied by status2: %d\n", sizeof(status2)); // 4
    printf("Memory size occupied by status3: %d\n", sizeof(status3)); // 4
    printf("Memory size occupied by status4: %d\n", sizeof(status4)); // 8

    Age.age =4;
    printf("Sizeof( Age ): %d\n", sizeof(Age)); // 4
    printf("Age.age: %d\n", Age.age);   // 4

    Age.age = 7;
    printf("Age.age: %d\n", Age.age);   // 7

    Age.age = 8;    // warning
    printf("Age.age: %d\n", Age.age);   // 0

    Age.age = 9;    // warning
    printf("Age.age: %d\n", Age.age);   // 1, truncated.

    return 0;
}
