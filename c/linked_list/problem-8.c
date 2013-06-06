#include "linked_list.h"

/*
Append 'b' onto the end of 'a', and then set 'b' to NULL.
 */
void Append(struct node** aRef, struct node** bRef) {
    struct node* current = *aRef;
    if (current == NULL) {
        *aRef = *bRef;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = *bRef;
    }
    *bRef = NULL;
}

/*
TODO: Why Append2() is wrong?
 */
void Append2(struct node** aRef, struct node** bRef) {
    struct node* current = *aRef;
    if (current == NULL) {
        *aRef = *bRef;
    } else {
        while (current != NULL) {
            current = current->next;
        }
        current = *bRef;
    }
    *bRef = NULL;
}

void AppendTest() {
    struct node* emptyList = NULL;
    struct node* a = BuildOneTwoThree();
    struct node* b = BuildThreeTwoOne();

    printf("Append b to a.\n");
    Print(a);
    Print(b);
    Append(&a, &b);
    Print(a);
    Print(b);

    printf("Append b to emptyList.\n");
    Print(emptyList);
    Print(b);
    Append(&emptyList, &b);
    Print(emptyList);
    Print(b);

    printf("Append a to emptyList.\n");
    Print(emptyList);
    Print(a);
    Append(&emptyList, &a);
    Print(emptyList);
    Print(a);
}

void Append2Test() {
    struct node* emptyList = NULL;
    struct node* a = BuildOneTwoThree();
    struct node* b = BuildThreeTwoOne();

    printf("Append b to a.\n");
    Print(a);
    Print(b);
    Append2(&a, &b);
    Print(a);
    Print(b);

    printf("Append b to emptyList.\n");
    Print(emptyList);
    Print(b);
    Append2(&emptyList, &b);
    Print(emptyList);
    Print(b);

    printf("Append a to emptyList.\n");
    Print(emptyList);
    Print(a);
    Append2(&emptyList, &a);
    Print(emptyList);
    Print(a);
}

int main(int argc, char const *argv[]) {
    AppendTest();
    Append2Test();
    return 0;
}
