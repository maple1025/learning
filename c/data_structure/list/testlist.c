#include <stdio.h>
#include "list.h"

int main(int argc, char *argv[])
{
    List L, L1, L2;
    Position P;
    int i;

    L = MakeEmpty(NULL);
    P = Header(L);
    PrintList(L, "\t");

    for (i = 0; i < 10; ++i)
    {
        Insert(i, L, P);
        P = Advance(P);
    }
    PrintList(L, "\t");

    for (i = 0; i < 10; i+=2)
    {
        printf("delete %d\n", i);
        Delete(i, L);
        PrintList(L, "\t");
    }

    for (i = 0; i < 10; ++i)
    {
        if ((i%2 == 0) == (Find(i, L) != NULL)){    /* brilliant */
            printf("delete error\n");
        }
    }

    L = MakeEmpty(L);
    P = Header(L);
    PrintList(L, "\t");

    for (i = 0; i < 10; ++i)
    {
        Insert(i, L, P);
        P = Advance(P);
    }
    PrintList(L, "\t");

    DeleteList(L);

    printf("----- test Append ...\n");
    L1 = MakeEmpty(NULL);
    L2 = MakeEmpty(NULL);
    for (i = 0; i < 10; ++i)
    {
        Insert(i, L1, L1);
        Insert(i*2, L2, L2);
    }
    PrintList(L1, "\t");
    PrintList(L2, "\t");
    Append(L1, L2);
    PrintList(L1, "\t");
    PrintList(L2, "\t");
    return 0;
}
