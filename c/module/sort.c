#include <stdio.h>
#include "stringarray.h"

int main()
{
    struct StringArray *stringarray = malloc(sizeof(struct StringArray));
    stringarray->nstrings = 0;

    ReadStrings(stringarray, stdin);
    SortStrings(stringarray);
    WriteStrings(stringarray, stdout);

    free(stringarray);

    return 0;
}