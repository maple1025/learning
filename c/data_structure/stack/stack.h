/*
 * http://see.stanford.edu/materials/icsppcs107/stack-implementation.pdf
 *
 * header file for stack
 */
#include <stdbool.h>

typedef struct {
    void *elems;
    int elemSize;
    int logLength;
    int allocLength;
} stack;

void StackNew(stack *s, int elemSize);
void StackDispose(stack *s);
bool StackEmpty(const stack *s);
void StackPush(stack *s, const void *elemAddr);
void StackPop(stack *s, void *elemAddr);
