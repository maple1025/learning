#include "polynomial.h"
#include "fatal.h"
#include <stdlib.h>

Polynomial MakeEmpty(Polynomial Poly)
{
    if (Poly != NULL){
        DeletePolynomial(Poly);
    }
    Poly = malloc(sizeof(struct Node));
    if (Poly == NULL) {
        FatalError("Out of memory");
    }
    Poly->Next = NULL;
    return Poly;
}

/*
 * Header assumed.
 */
int IsLast(Polynomial Poly)
{
    return Poly->Next == NULL;
}

/*
 * Delete the Polynomial
 */
void DeletePolynomial(Polynomial Poly)
{
    Polynomial Ptr, Tmp;
    Ptr = Poly->Next;
    while (Ptr != NULL){
        Tmp = Ptr->Next;
        free(Ptr);
        Ptr = Tmp;
    }
    Poly->Next = NULL;
}

/*
 * Cells are sorted in decreasing order of exponent
 */
void Insert(Polynomial Poly, int c, int e)
{
    Polynomial P, Tmp, New;
    // if Poly->Next == NULL, append new node
    P = Poly;
    while (P->Next != NULL){
        if (P->Next->Exponent == e){
            P->Next->Coefficient += c;
            return;
        } else if (P->Next->Exponent > e){
            P = P->Next;
        } else if (P->Next->Exponent < e){
            New = malloc(sizeof(struct Node));
            Tmp = P->Next;
            P->Next = New;
            New->Coefficient = c;
            New->Exponent = e;
            New->Next = Tmp;
            return;
        }
    }
    New = malloc(sizeof(struct Node));
    P->Next = New;
    New->Coefficient = c;
    New->Exponent = e;
    New->Next = NULL;
}

Polynomial AddPolynomial(const Polynomial Poly1, const Polynomial Poly2)
{
    Polynomial P1, P2, PolySum;
    PolySum = MakeEmpty(NULL);
    P1 = Poly1->Next;
    P2 = Poly2->Next;
    while (P1 != NULL){
        Insert(PolySum, P1->Coefficient, P1->Exponent);
        P1 = P1->Next;
    }
    while (P2 != NULL){
        Insert(PolySum, P2->Coefficient, P2->Exponent);
        P2 = P2->Next;
    }
    return PolySum;
}

Polynomial MultPolynomial(const Polynomial Poly1, const Polynomial Poly2)
{
    Polynomial P1, P2, PolyProd;
    PolyProd = MakeEmpty(NULL);
    P1 = Poly1->Next;
    while(P1 != NULL){
        P2 = Poly2->Next;
        while(P2 != NULL){
            Insert(PolyProd, P1->Coefficient * P2->Coefficient, P1->Exponent + P2->Exponent);
            P2 = P2->Next;
        }
        P1 = P1->Next;
    }
    return PolyProd;
}
