#include <stdio.h>
#include <stdlib.h>

/*
Given a list and an int, return the number of times that int occurs
in the list.
 */
int Count(struct node* head, int searchFor){
    struct node * current = head;
    int num = 0;
    while (current != NULL){
        if (current->data == searchFor){
            num ++;
        }
        current = current->next;
    }
    return num;
}

void CountTest() {
    struct node* myList = BuildOneTwoThree();

    int count = Count(myList, 0);
    printf("%d\n", count);
}

int main() {
    CountTest();
}
