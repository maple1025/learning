#include <stdio.h>
#include "polynomial.h"

void PrintPolynomial(const Polynomial Poly)
{
    Polynomial Tmp;
    if (IsLast(Poly)) {
        printf("empty polynomial\n");
    } else{
        Tmp = Poly;
        do {
            Tmp = Tmp->Next;
            printf("%d*x^%d\t", Tmp->Coefficient, Tmp->Exponent);
        } while(Tmp->Next != NULL);
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    Polynomial Poly, Poly1, Poly2, PolySum, PolyProd;
    int i;
    printf("\n#### Test Basic Operations ...\n");
    Poly = MakeEmpty(NULL);
    PrintPolynomial(Poly);

    printf("insert Coefficient: %d, Exponent: %d\n", 3, 4);
    Insert(Poly, 3, 4);
    PrintPolynomial(Poly);
    for (i = 0; i < 10; ++i)
    {
        printf("insert Coefficient: %d, Exponent: %d\n", i, i*2);
        Insert(Poly, i, i*2);
    }
    PrintPolynomial(Poly);
    DeletePolynomial(Poly);
    PrintPolynomial(Poly);
    for (i = 0; i < 10; ++i)
    {
        printf("insert Coefficient: %d, Exponent: %d\n", i, i*2);
        Insert(Poly, i, i*2);
    }
    PrintPolynomial(Poly);

    Poly1 = MakeEmpty(NULL);
    Poly2 = MakeEmpty(NULL);

    printf("\n#### Test AddPolynomial ...\n");
    for (i = 0; i < 10; ++i)
    {
        Insert(Poly1, i + 1, i*2);
        Insert(Poly2, i + 2, i*3);
    }
    PrintPolynomial(Poly1);
    PrintPolynomial(Poly2);
    PolySum = AddPolynomial(Poly1, Poly2);
    PrintPolynomial(PolySum);

    printf("\n#### Multiply AddPolynomial ...\n");
    Poly1 = MakeEmpty(NULL);
    Poly2 = MakeEmpty(NULL);

    for (i = 0; i < 10; ++i)
    {
        Insert(Poly1, i + 1, i*2);
        Insert(Poly2, i + 2, i*3);
    }
    PrintPolynomial(Poly1);
    PrintPolynomial(Poly2);
    PolyProd = MultPolynomial(Poly1, Poly2);
    PrintPolynomial(PolyProd);
    return 0;
}



