#include <stdio.h>
#include <stdlib.h>

/* Linked list node structure */
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

/* Function to create a new node */
struct Node * createNode(struct Node * newNode, int data){
    newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node * reverseList(struct Node * head) {
    /* Write your code here */	


    ////////////////////
}

/* Do not modify below */	
int main(int argc, char* argv[])
{  
    int length = argc - 1;

    /* Create a linked list from input integers */
    // int k = 1;
    struct Node * head = NULL;
    struct Node * prev = NULL;
    struct Node * curr = NULL;

    for (int k = 1; k <= length; k++) {
        curr = createNode(curr, atoi(argv[k]));

        if (k > 1)
        prev->next = curr;
        else
        head = curr;

        prev = curr;
    }
    /* Reverse linked list */
    head = reverseList(head);

    /* Print reversed linked list */
    curr = head;
    while (curr){
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
    return 0;
}

/*
Compile command
---------------
gcc p2.c -o p2

Test cases
----------
./p2 1 2 3 4 5
5 4 3 2 1

./p2 10 20 30
30 20 10
*/