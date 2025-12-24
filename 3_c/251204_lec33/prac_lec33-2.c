#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType LinkedNode;
struct nodeType {
    int val;
    LinkedNode *next;
}; // node type 정의 시 semicolumn


LinkedNode *createNode(int x) {
    LinkedNode *newNode;
    newNode = (LinkedNode*) malloc(sizeof(LinkedNode));
    newNode -> val = x;
    newNode -> next = NULL;
    return newNode;
}

typedef struct listType SLList;
struct listType {
    LinkedNode *first;
    int size;
};

int getFirst(SLList *LL);
void addFirst(SLList *LL, int x);
int getSize(SLList *LL);
void printSLList(SLList *LL);
LinkedNode *searchNode(SLList *LL, int x);
void deleteNode(SLList *LL, int x);

int main (void) {
    SLList myLL = {NULL, 0};
    printSLList(&myLL);

    addFirst(&myLL, 10);
    printSLList(&myLL);

    addFirst(&myLL, 20);
    printSLList(&myLL);

    addFirst(&myLL, 30);
    printSLList(&myLL);

    deleteNode(&myLL, 20);
    printSLList(&myLL);

    deleteNode(&myLL, 30);
    printSLList(&myLL);

    return 0;
}

// Function definition
void deleteNode(SLList *LL, int x){
    LinkedNode *curr = LL -> first;
    LinkedNode *prev = NULL;

    while (curr != NULL) {
        if (curr -> val == x) {
            if (curr == LL->first) {
                LL -> first = LL -> first -> next;
            }
            else {
                prev->next = curr->next;
            }
            free(curr);
            LL->size--;
            return;
        }
        else {
            prev = curr;
            curr = curr -> next;
        }
    }
}


LinkedNode *searchNode(SLList *LL, int x) {
    LinkedNode *curr = LL->first;

    while (curr != NULL) {
        if (curr -> val == x) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}


void printSLList(SLList *LL) {
    LinkedNode *curr = LL -> first;
    printf("size : %d, firstVal: %d, allVals: ", getSize(LL), getFirst(LL));
    while(curr != NULL) {
        printf("%d->", curr->val);
        curr = curr -> next;
    }
    printf("END\n");
}

int getSize(SLList *LL) {
    return LL->size;
}

int getFirst(SLList *LL) {
    if (LL->first != NULL) {
        return LL -> first -> val;
    }
    return 0;
}

void addFirst(SLList *LL, int x) {
    LinkedNode *newFirst = createNode(x);
    newFirst -> next = LL->first;
    LL->first = newFirst;
    LL->size++;
}