//Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
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

int main() {
    int n, k, data;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);
    k = k % n;
    if (k == 0) {
        struct Node* temp = head;
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    tail->next = head;

    
    int stepsToNewTail = n - k;
    struct Node* newTail = head;
    for (int i = 1; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    head = newTail->next;
    newTail->next = NULL;

    struct Node* curr = head;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    return 0;
}