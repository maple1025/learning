
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#define kInitialAllocationSize 4

/*
 * The constructor requires that the client element size to be identified up
 * front. Since it doesn't (and will never) know the true data type.
 */
void StackNew(stack *s, int elemSize)
{
    assert(elemSize > 0);
    s->elemSize = elemSize;
    s->logLength - 0;
    s->allocLength = kInitialAllocationSize;
    s->elems = malloc(kInitialAllocationSize * elemSize);
    assert(s->elems != NULL);
}

/* The destructor simply needs to dispose of any resources that'll otherwise be
 * orphande.
 *
 * Note that we don't call free(s). StackNew doesn't allocate space for the
 * stack struct -- the client does! The stack destructor should noly clean up
 * its own mess, not someone else's.
 */
void StackDispose(stack *s)
{
    free(s->elems);
}


bool StackEmpty(const stack *s)
{
    return s->logLength == 0;
}

void StackPush(stack *s, const void *elemAddr)
{
    void *destAddr;
    if (s->logLength == s->allocLength){
        s->allocLength *= 2;
        s->elems = realloc(s->elems, s->allocLength * s->elemSize);
        assert(s->elems != NULL);
    }

    destAddr = (char*)s->elems + s->logLength * s->elemSize;
    memcpy(destAddr, elemAddr, s->elemSize);
    s->logLength++;
}

void StackPop(stack *s, void *elemAddr)
{
    const void *sourceAddr;

    assert(!StackEmpty(s));
    s->logLength--;
    sourceAddr = (const char*)s->elems + s->logLength * s->elemSize;
    memcpy(elemAddr, sourceAddr, s->elemSize);
}
