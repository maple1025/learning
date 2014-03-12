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

/*
 * Return Position of X in L; NULL if not found
 */
Position Find(ElementType X, List L)
{
    List P;
    P = L->Next;
    while (P != NULL && P->Elment != X){    /* brilliant */
        P = P->Next;
    }
    return P;
}

/*
 * Delete X from a List L
 * Cell pointed to by Prev->Next is wiped out
 * Assume use of a header note
 */
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

/*
 * If X is not found, then Next field of returned value is NULL
 * Assumes a header
 */
Position FindPrevious(ElementType X, List L)
{
    List P;
    P = L;
    while (P->Next != NULL & P->Next->Elment != X)
        P = P->Next;
    return P;
}

/*
 * Insert (after legal position P)
 * Header assumed
 */
void Insert(ElementType X, List L, Position P)
{
    List NewNode;
    NewNode = malloc(sizeof(struct Node));
    if (NewNode == NULL)
        FatalError("Out of memory.");
    NewNode->Elment = X;
    NewNode->Next = P->Next;
    P->Next = NewNode;
}

void DeleteList(List L)
{
    List P, Tmp;
    P = L->Next;    /* Header assumed */
    L->Next = NULL;
    while (P != NULL){
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

Position Header(List L)
{
    return L;
}

Position First(List L)
{
    return L->Next;
}

Position Advance(Position P)
{
    return P->Next;
}

ElementType Retrieve(Position P)
{
    return P->Elment;
}
