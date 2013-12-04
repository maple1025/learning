#include <stdio.h>

int main(int argc, char *argv[])
{
    char *ps = "abc";
    printf("str is %s\n", ps);
    ps[0] = "d";
    printf("str is %s\n", ps);
}
