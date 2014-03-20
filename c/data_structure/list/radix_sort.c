#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "list.h"

List radix_sort(List L, int base);

int main(int argc, char *argv[])
{
    List InputList;
    int base = 10;
    int i;
    InputList = MakeEmpty(NULL);
    for (i = 0; i < 30; ++i)
    {
        Insert(rand(), InputList, InputList);
    }
    PrintList(InputList, "\n");
    printf("max of above list is %d\n", Max(InputList));
    PrintList(radix_sort(InputList, base), "\n");
    return 0;
}

List radix_sort(const List L, int base)
{
    List Buckets[base - 1];
    List NewList = L;
    Position P;
    int NumOfPass, i, j, BucketNum;
    NumOfPass = (int) log(Max(L)) / log(base) + 1;
    for (i = 0; i < NumOfPass; ++i)
    {
        for (j = 0; j < base; ++j)
        {
            Buckets[j] = MakeEmpty(NULL);
        }
        P = First(NewList);
        while(P != NULL){
            BucketNum = (Retrieve(P) % (int) pow(base, i+1)) / pow(base, i);
            Append(Retrieve(P), Buckets[BucketNum]);
            P = Advance(P);
        }
        /* merge buckets into NewList */
        NewList = MakeEmpty(NULL);
        for (j = 0; j < base; ++j)
        {
            Merge(NewList, Buckets[j]);
        }
    }

    return NewList;
}
