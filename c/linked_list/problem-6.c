#include "linked_list.h"

/*
Given a list that is sorted in increasing order.
Insert a single node into the correct sorted position in the list.
 */

void SortedInsert(struct node** headRef, struct node* newNode) {
    struct node* current = *headRef;
    struct node** currentRef = headRef;
    int count = 0;
    while (current != NULL) {
        if (current->data > newNode->data) {
            break;
        }
        count ++;
        current = current->next;
    }
    if (current != NULL) {
        count =  count - 1;
    }
    current = *headRef;
    while (count > 0) {
        currentRef = &(*currentRef)->next;
        current = current->next;
        printf("currentRef is %p, *currentRef is %p\n", currentRef, *currentRef);
        count --;
    }
    *currentRef = newNode;
    newNode->next = current;
}

void SortedInsertTest() {
    struct node* myList = BuildOneTwoThree();
    struct node* node1 = malloc(sizeof(struct node));
    struct node* node2 = malloc(sizeof(struct node));
    struct node* node3 = malloc(sizeof(struct node));

    node1->data = 0;
    node1->next = NULL;
    node2->data = 2;
    node2->next = NULL;
    node3->data = 5;
    node3->next = NULL;

    Print(myList);
    SortedInsert(&myList, node1);
    Print(myList);
    SortedInsert(&myList, node2);
    Print(myList);
    SortedInsert(&myList, node3);
    Print(myList);
}

int main(int argc, char const *argv[]) {
    SortedInsertTest();
    return 0;
}
