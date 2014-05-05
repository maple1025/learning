#include "linked_list.h"

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
