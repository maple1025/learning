#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 256

void ReadStrings(FILE *fp, char **strings, int *nstrings, int maxstrings)
{
    char string[MAX_STRING_LENGTH];

    //*nstrings = 0;
    while (fgets(string, MAX_STRING_LENGTH, fp)) {
        strings[(*nstrings)++] = strdup(string);
        if (*nstrings >= maxstrings) break;
    }
}

void WriteStrings(FILE *fp, char **strings, int nstrings)
{
    int i;

    for (i = 0; i < nstrings; i++)
    {
        fprintf(fp, "%s", strings[i]);
    }
}

int CompareStrings(char *string1, char *string2)
{
    char *p1, *p2;

    for (p1 = string1, p2 = string2; *p1 && *p2; p1++, p2++) {
        if (*p1 < *p2)
            return -1;
        else if (*p1 > *p2)
            return 1;
    }

    return 0;
}

void SortStrings(char **strings, int nstrings)
{
    int i, j;

    for (i = 0; i < nstrings; i++)
    {
        for (j = i+1; j < nstrings; j++) {
            if (CompareStrings(strings[i], strings[j]) > 0) {
                char *swap = strings[i];
                strings[i] = strings[j];
                strings[j] = swap;
            }
        }
    }
}