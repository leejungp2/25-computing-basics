#include<stdio.h>
#include<stdlib.h>

/* Linked list node structure */

struct Node
{
    int data;
    struct Node* next;
};


struct Node* mergeTwoLists(struct Node* a, struct Node* b){
    // write your code here
    struct Node dummy;
    struct Node* tail = &dummy;

    // while (a != NULL && b != NULL) {
    while (a && b) {
        if (a -> data > b -> data) {
            tail -> next = b;
            b = b -> next;
        } else {
            tail -> next = a;
            a = a -> next;
        }
        tail = tail -> next;
    }
    
    if (a) {
        tail -> next = a;
    } else {
        tail -> next = b;
    }

    return dummy.next;
    ////////////////////
}
    // DO NOT MODIFY BELOW

/* Function to create a new node */
struct Node * createNode(int x){
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}
typedef struct listType SLList;
struct listType{
    struct Node *first;
    int size;
};

void addFirst(SLList *LL, int x);

int main(int argc, char* argv[]){
    SLList list_a = {NULL, 0};
    SLList list_b = {NULL, 0};
    for(int i = 0; i < (argc-1)/2; i++)
        addFirst(&list_a, atoi(argv[(argc-1)/2-i])); 

    for(int i = 0; i < argc/2; i++){
        addFirst(&list_b, atoi(argv[(argc-1)-i]));
        }
    struct Node *c;
    c =  mergeTwoLists(list_a.first, list_b.first);
    // print merged lists
    while (c){
        printf("%d ", c ->data);
        c = c->next;
    }
    printf("\n");
}

void addFirst(SLList *LL, int x){
    struct Node *newFirst;
    newFirst = createNode(x);
    newFirst -> next = LL -> first;
    LL -> first = newFirst;
    LL -> size++;
}

/*
Compile command
---------------
gcc p1.c -o p1

Test cases
----------
./p1 1 3 5 7 2 4 6 8
1 2 3 4 5 6 7 8

./p1 1 5 8 3 6 9
1 3 5 6 8 9
*/