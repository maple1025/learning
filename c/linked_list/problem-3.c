#include "linked_list.h"

/*
Deallocate all memory of a linked_list, and set its head pointer to NULL.
 */

void DeleteList(struct node** headRef) {
    struct node* current = *headRef;
    while (current != NULL) {
        struct node* tmp = current->next;
        printf("free %p\n", current);
        free(current);
        current = tmp;
    }
    *headRef = NULL;
}


void DeleteListTest() {
    struct node* myList = BuildOneTwoThree();

    DeleteList(&myList);
    printf("After delete, head of the list is: %p\n", myList);
}

int main(int argc, char const *argv[]) {
    DeleteListTest();
    return 0;
}
