#include <stdio.h>
#include "list.h"

void PrintList(const List L)
{
    Position P, Tmp;
    P = Header(L);
    if (IsEmpty(L)){
        printf("empty list\n");
    } else {
        do {
            P = Advance(P);
            printf("%d\t", Retrieve(P));
        } while(!IsLast(P, L));
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    List L;
    Position P;
    int i;

    L = MakeEmpty(NULL);
    P = Header(L);
    PrintList(L);

    for (i = 0; i < 10; ++i)
    {
        printf("insert %d\n", i);
        Insert(i, L, P);
        P = Advance(P);
        PrintList(L);
    }

    for (i = 0; i < 10; i+=2)
    {
        printf("delete %d\n", i);
        Delete(i, L);
        PrintList(L);
    }

    for (i = 0; i < 10; ++i)
    {
        if ((i%2 == 0) == (Find(i, L) != NULL)){    /* brilliant */
            printf("delete error\n");
        }
    }

    L = MakeEmpty(L);
    P = Header(L);
    PrintList(L);

    for (i = 0; i < 10; ++i)
    {
        printf("insert %d\n", i);
        Insert(i, L, P);
        P = Advance(P);
        PrintList(L);
    }

    DeleteList(L);
    return 0;
}
