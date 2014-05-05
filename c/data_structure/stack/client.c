/*
 * client file for stack
 */

#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[])
{
    int val;
    stack intStack;

    StackNew(&intStack, sizeof(int));

    for (val = 0; val < 6; val++)
        StackPush(&intStack, &val);

    while(!StackEmpty(&intStack)){
        StackPop(&intStack, &val);
        printf("This just popped: %d\n", val);
    }
    StackDispose(&intStack);
    return 0;
}
