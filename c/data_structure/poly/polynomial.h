typedef struct Node *PtrToNode;

struct Node
{
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};

typedef PtrToNode Polynomial;

Polynomial MakeEmpty(Polynomial Poly);
int IsLast(Polynomial Poly);
void Insert(Polynomial Poly, int c, int e);
void DeletePolynomial(Polynomial Poly);
Polynomial AddPolynomial(const Polynomial Poly1, const Polynomial Poly2);
Polynomial MultPolynomial(const Polynomial Poly1, const Polynomial Poly2);
