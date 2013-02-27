#define MAX_STRINGS 128

extern void ReadStrings(char **strings, int *nstrings, int maxstrings, FILE *fp);
extern void WriteStrings(char **strings, int nstrings, FILE *fp);
extern void SortStrings(char **strings, int nstrings);
extern int CompareStrings(char *string1, char *string2);