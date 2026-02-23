//Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct ListNode** head, int val) {
    struct ListNode* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct ListNode* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d -> ", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* curr = &dummy;
    dummy.next = NULL;

    while (list1 && list2) {
        if (list1->val <= list2->val) {
            curr->next = list1;
            list1 = list1->next;
        } else {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }
    curr->next = list1 ? list1 : list2;
    return dummy.next;
}

int main() {
    struct ListNode *list1 = NULL, *list2 = NULL;
    int n1, n2, val;

    printf("Enter number of elements for List 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &val);
        insertEnd(&list1, val);
    }

    printf("Enter number of elements for List 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &val);
        insertEnd(&list2, val);
    }

    printf("\nList 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    struct ListNode* mergedHead = mergeTwoLists(list1, list2);

    printf("Merged List: ");
    printList(mergedHead);

    return 0;
}