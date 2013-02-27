#define MAX_STRINGS 128

typedef struct StringArray
{
    char *strings[MAX_STRINGS];
    int nstrings;
} *StringArray_T;

extern void ReadStrings(StringArray_T *stringarray, FILE *fp);
extern void WriteStrings(StringArray_T *stringarray, FILE *fp);
extern void SortStrings(StringArray_T *stringarray);