#include "linked_list.h"
/*
Given a list, change it to be in increasing order (using SortedInsert()).
 */
void InsertSort(struct node** headRef){
    struct node* new = NULL;
    struct node* current = *headRef;
    struct node* tmp = NULL;
    while (current != NULL) {
        tmp = current->next;
        SortedInsert(&new, current);
        current = tmp;
    }
    *headRef = new;
}

void InsertSortTest(){
    struct node* myList = BuildThreeTwoOne();
    printf("pointer in myList: %p, %p, %p, %p\n", myList, myList->next, myList->next->next, myList->next->next->next);
    Print(myList);
    InsertSort(&myList);
    Print(myList);
}

int main(int argc, char const *argv[]) {
    InsertSortTest();
    return 0;
}
