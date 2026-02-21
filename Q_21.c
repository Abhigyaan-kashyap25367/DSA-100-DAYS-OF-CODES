//Problem: Create and Traverse Singly Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void LinkedListTraversal(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    int n, data;
    struct Node* head = NULL;
    printf("Enter the total number of linked list = ");

    scanf("%d", &n);
    printf("Enter the linked list = ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(&head, data);
    }
    LinkedListTraversal(head);

    return 0;
}