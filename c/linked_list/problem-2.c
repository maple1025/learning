#include <assert.h>
#include "linked_list.h"

/*
Given a list and an index, return the data
in the nth node of the list. The nodes are numbered from 0.
Assert fails if the index is invalid (outside 0..length-1).
 */
int GetNth(struct node* head, int index) {
    struct node* current = head;
    int i;
    for (i = 0; i < index; i++) {
        printf("index is %d, current pointer is %p\n", i, current);
        if (current == NULL) {
            printf("index outof range.\n");
            exit(1);
        } else {
            current = current->next;
        }
    }
    /*
    without the last test, it will cause runtime error, segmentation fault.
     */
    if (current == NULL) {
        printf("index out of range.\n");
        exit(1);
    } else {
        return current->data;
    }
}

/*
Another version of GetNth.
 */
int GetNth2(struct node* head, int index) {
    struct node* current = head;
    int i = 0;
    while (current != NULL) {
        if (i == index) {
            return current->data;
        }
        i ++;
        current = current->next;
    }
    printf("index out of range\n");
    exit(1);
}

void TestGetNth() {
    struct node* myList = BuildOneTwoThree();
    int data = GetNth(myList, 3);
    printf("%d\n", data);
}

void TestGetNth2() {
    struct node* myList = BuildOneTwoThree();
    int data = GetNth2(myList, 2);
    printf("%d\n", data);
}

int main(int argc, char const *argv[])
{
    TestGetNth2();
    return 0;
}
