#include <stdlib.h>
#include "list.h"
#include "fatal.h"

struct Node
{
    ElementType Elment;
    Position Next;
};


List MakeEmpty(List L)
{
    if (L != NULL){
        DeleteList(L);
    }
    L = malloc(sizeof(struct Node));
    if (L == NULL){
        FatalError("Out of memory!");
    }
    L->Next = NULL;
    return L;
}

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
    List P;
    P = L->Next;
    while (P != NULL && P->Elment != X){    /* brilliant */
        P = P->Next;
    }
    return P;
}

void Delete(ElementType X, List L)
{
    List Tmp, Prev;
    Prev = FindPrevious(X, L);
    if (!IsLast(Prev, L)){
        Tmp = Prev->Next;
        Prev->Next = Tmp->Next;
        free(Tmp);
    }
}

void DeleteList(List L)
{
    List P, Tmp;
    P = L->Next;    /* Header assumed */
    L->Next = NULL;
    while (P != NULL){
        Tmp = P->Next;
        free(P);
        L = Tmp;
    }
}
