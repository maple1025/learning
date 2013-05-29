#include "linked_list.h"

/*
The opposite of Push(). Takes a non-empty list
and removes the front node, and return the data
which was in that node.
 */
int Pop(struct node** headRef) {
    int d;
    struct node* tmp;
    if (*headRef == NULL) {
        printf("List empty, has no eliment to pop.\n");
        exit(1);
    }
    d = (*headRef)->data;
    tmp = (*headRef)->next;
    free(*headRef);
    *headRef = tmp;
    return d;
}

void PopTest() {
    struct node* myList = BuildOneTwoThree();
    int len = Length(myList);
    printf("The origin length of the list is: %d\n", len);
    int a = Pop(&myList);
    int b = Pop(&myList);
    int c = Pop(&myList);
    len = Length(myList);
    printf("a, b, c are: %d, %d, %d\n", a, b, c);
    printf("After pop a, b, c, length of the list is: %d\n", len);
}

int main(int argc, char const *argv[]) {
    PopTest();
    return 0;
}
