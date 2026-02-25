//Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }
    return count;
}

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

int main() {
    struct Node* head = NULL;
    int n, value, key;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 1;

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Enter key to count: ");
    scanf("%d", &key);

    printf("Occurrences of %d: %d\n", key, countOccurrences(head, key));

    return 0;
}