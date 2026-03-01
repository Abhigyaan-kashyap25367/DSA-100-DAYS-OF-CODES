//Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.
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

int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head1) head1 = tail1 = newNode;
        else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    if (scanf("%d", &m) != 1) return 0;
    struct Node* intersectNode = NULL;
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        
        struct Node* temp = head1;
        struct Node* found = NULL;
        while(temp) {
            if(temp->data == val) {
                found = temp;
                break;
            }
            temp = temp->next;
        }

        if (found && !intersectNode) {
            intersectNode = found;
            if (!head2) head2 = tail2 = intersectNode;
            else {
                tail2->next = intersectNode;
                tail2 = intersectNode;
            }
            break; 
        } else {
            struct Node* newNode = createNode(val);
            if (!head2) head2 = tail2 = newNode;
            else {
                tail2->next = newNode;
                tail2 = newNode;
            }
        }
    }

    int len1 = getLength(head1);
    int len2 = getLength(head2);
    struct Node *ptr1 = head1, *ptr2 = head2;

    int diff = abs(len1 - len2);
    if (len1 > len2) {
        for (int i = 0; i < diff; i++) ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++) ptr2 = ptr2->next;
    }

    while (ptr1 && ptr2) {
        if (ptr1 == ptr2) {
            printf("%d\n", ptr1->data);
            return 0;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection\n");
    return 0;
}