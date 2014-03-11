/*
 Demo code from http://cslibrary.stanford.edu/103/
 About linked_list and pointer.
 */

struct node
{
    int             data;
    struct node *   next;
};

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
 Given a linked list head pointer, compute
 and return the number of nodes in the list.
 */
 int Length(struct node* head){
    struct node* current = head;    /* what happen if not use a local variable current? */
    int count = 0;
    while (head != NULL){
        current = current->next;
        count ++;
    }
    return count;
 }

void LengthTest(){
    struct node* myList = BuildOneTwoThree();
    int len = Length(myList);
    return len;
}

/*
 Take a list and a data value.
 Create a new link with the given data and pushes
 it onto the front of the list.
 The list is not passed by its head pointer.
 Instead the list is passed in as a "reference" pointer
 to the head pointer -- this allows us to modify
 the caller's memory.
 */
void Push(struct node** headRef, int data){
    newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

void PushTest(){
    struct node* head = BuildTwoThree();

    Push(&head, 1);
    Push(&head, 13);
}

struct node* AppendNode(struct node** headRef, int num){
    struct node* current = *headRef;
    struct node* newNode;

    newNode = malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = NULL;

    if (current == NULL){
        *headRef = newNode;
    } else{
        while (current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

struct node* AppendNode(struct node** headRef, int num){
    struct node* current = *headRef;

    if (current == NULL){
        Push(&current, num);
    } else{
        while (current->next != NULL){
            current = current->next;
        }
        Push(&(current->next), num);
    }
}

struct node* CopyList(struct node* head){
    struct node* current = head;
    struct node* tail = NULL;
    struct node* newList = NULL;

    while (current != NULL){
        if (newList == NULL){
            newList = malloc(sizeof(struct node));
            newList->data = current->data;
            newList->next = NULL;
            tail = newList;
        } else{
            tail->next = malloc(sizeof(struct node));
            tail = tail->next;
            tail->data = current->data;
        }
    }
}

void BasicsCaller(){
    struct node* head;
    int len;

    head = BuildOneTwoThree();

    Push(&head, 13);

    Push(&(head->next), 42);

    len = Length(head);

}
