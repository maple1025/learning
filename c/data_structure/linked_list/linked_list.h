#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* BuildOneTwoThree();
struct node* BuildThreeTwoOne();

int Length(struct node*);

void Print(struct node*);

void SortedInsert(struct node**, struct node*);
