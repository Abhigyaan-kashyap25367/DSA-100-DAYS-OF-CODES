// Problem Statement
// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int sum;
    int index;
    struct Node* next;
};

#define TABLE_SIZE 10007

void insert(struct Node** hashTable, int sum, int index) {
    int hash = abs(sum) % TABLE_SIZE;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = hashTable[hash];
    hashTable[hash] = newNode;
}

int find(struct Node** hashTable, int sum) {
    int hash = abs(sum) % TABLE_SIZE;
    struct Node* temp = hashTable[hash];
    while (temp != NULL) {
        if (temp->sum == sum) return temp->index;
        temp = temp->next;
    }
    return -2; 
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* hashTable[TABLE_SIZE] = {NULL};
    int prefixSum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            maxLength = i + 1;
        } else {
            int prevIndex = find(hashTable, prefixSum);
            if (prevIndex != -2) {
                int len = i - prevIndex;
                if (len > maxLength) maxLength = len;
            } else {
                insert(hashTable, prefixSum, i);
            }
        }
    }

    printf("%d\n", maxLength);

   
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* curr = hashTable[i];
        while (curr) {
            struct Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    return 0;
}