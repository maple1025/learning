#include <stdio.h>
#include <stdlib.h>
#include "stringarray.h"

#define MAX_STRINGS 128

int main()
{
    char *strings[MAX_STRINGS];
    int nstrings = 10;

    ReadStrings(strings, &nstrings, MAX_STRINGS, stdin);
    SortStrings(strings, nstrings);
    WriteStrings(strings, nstrings, stdout);

    return 0;
}