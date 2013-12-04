#include "linked_list.h"

/*
A more general version of Push().
Given a list, an index 'n' in the range 0..length,
and a data element, add a new node to the list so
that it has the given index.
 */
void InsertNth(struct node** headRef, int index, int data) {
    struct node* current = *headRef;
    struct node** currentRef =headRef;
    struct node* newNode = malloc(sizeof(struct node));
    int count = 0;
    while (count < index) {
        if (current == NULL) {
            printf("Insert out of range.\n");
            exit(1);
        } else {
            currentRef = &((*currentRef)->next);
            current = current->next;
            printf("print the list begin from current in round %d:\n", count);
            Print(current);
            count ++;
        }
    }
    *currentRef = newNode;
    newNode->data = data;
    newNode->next = current;
}

void InsertNthTest() {
    struct node* head = NULL;
    int len = 0;

    len = Length(head);
    printf("Before insert, length of the list is: %d\n", len);
    // Print(head);
    InsertNth(&head, 0, 13);
    // Print(head);
    InsertNth(&head, 1, 42);
    // Print(head);
    InsertNth(&head, 2, 5);
    // Print(head);
    InsertNth(&head, 1, 3);
    // Print(head);
    InsertNth(&head, 0, 9);
    // Print(head);
    InsertNth(&head, 4, 11);
    // Print(head);
    len = Length(head);
    printf("After insert, length of the list is: %d\n", len);
    Print(head);
}

int main(int argc, char const *argv[]) {
    InsertNthTest();
    return 0;
}
