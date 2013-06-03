#include "linked_list.h"
/*
 Build the list {1, 2, 3} in the heap and store
 its head pointer in a local stack variable.
 Returns the head pointer to the caller.
 */
struct node* BuildOneTwoThree(){
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    return head;
}

/*
Get the length of a linked list.
 */
int Length(struct node* head) {
    struct node* current = head;
    int count = 0;
    while (current != NULL) {
        count ++;
        current = current->next;
    }
    return count;
}

/*
Print datas in a list in order.
 */

void Print(struct node* head) {
    struct node* current = head;
    printf("List: HEAD -> ");
    while (current != NULL) {
       printf("%d -> ", current->data);
       current = current->next;
    }
    printf("NULL\n");
}

