#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* start) {
    while (start != NULL) {
        printf("%d -> ", start->data);
        start = start->next;
    }
    printf("NULL\n");
}

void swapNodes(struct Node** start, int a, int b) {
    if (*start == NULL || a == b) {
        return;
    }

    struct Node *prevA = NULL, *currA = *start;
    while (currA != NULL && currA->data != a) {
        prevA = currA;
        currA = currA->next;
    }

    struct Node *prevB = NULL, *currB = *start;
    while (currB != NULL && currB->data != b) {
        prevB = currB;
        currB = currB->next;
    }

    if (currA == NULL || currB == NULL) {
        return;
    }

    if (prevA != NULL) {
        prevA->next = currB;
    } else {
        *start = currB;
    }

    if (prevB != NULL) {
        prevB->next = currA;
    } else {
        *start = currA;
    }

    struct Node* temp = currA->next;
    currA->next = currB->next;
    currB->next = temp;
}

int main() {
    struct Node* start = createNode(1);
    start->next = createNode(2);
    start->next->next = createNode(3);
    start->next->next->next = createNode(4);
    start->next->next->next->next = createNode(5);

    printf("Original Linked List:\n");
    printList(start);

    int nodeA = 1, nodeB = 4;
    swapNodes(&start, nodeA, nodeB);

    printf("\nLinked List after swapping %d and %d:\n", nodeA, nodeB);
    printList(start);

    return 0;
}

