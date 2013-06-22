#include "linked_list.h"
/*
Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
 */
void FrontBackSplit(struct node* source,
                    struct node** frontRef, struct node** backRef) {
    int length = Length(source);
}

void FrontBackSplitTest() {
    struct node* empty_list = BuildEmpty();
    struct node* list1 = BuildOne();
    struct node* list2 = BuildOneTwo();
    struct node* list3 = BuildOneThree();
    struct node* list4 = BuildOneThreeFour();
    struct node* front = NULL;
    struct node* back = NULL;

    printf("** test case 1 **\n");
    printf("origin list:\n");
    Print(empty_list);
    FrontBackSplit(empty_list, front, back);
    printf("After split:\n");
    Print(front);
    Print(back);

    printf("** test case 2 **\n");
    printf("origin list:\n");
    Print(list1);
    FrontBackSplit(list1, front, back);
    printf("After split:\n");
    Print(front);
    Print(back);

    printf("** test case 3 **\n");
    printf("origin list:\n");
    Print(list2);
    FrontBackSplit(list2, front, back);
    printf("After split:\n");
    Print(front);
    Print(back);

    printf("** test case 4 **\n");
    printf("origin list:\n");
    Print(list3);
    FrontBackSplit(list3, front, back);
    printf("After split:\n");
    Print(front);
    Print(back);

    printf("** test case 5 **\n");
    printf("origin list:\n");
    Print(list4);
    FrontBackSplit(list4, front, back);
    printf("After split:\n");
    Print(front);
    Print(back);
}

int main(int argc, char const *argv[]) {
    FrontBackSplitTest();
    return 0;
}
