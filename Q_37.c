//Problem Statement: Implement a Priority Queue using an array. An element with smaller value has higher priority.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int *array;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->array = (int*)malloc(capacity * sizeof(int));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void siftUp(PriorityQueue* pq, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (pq->array[idx] < pq->array[parent]) {
            swap(&pq->array[idx], &pq->array[parent]);
            idx = parent;
        } else break;
    }
}

void siftDown(PriorityQueue* pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->array[left] < pq->array[smallest])
        smallest = left;
    if (right < pq->size && pq->array[right] < pq->array[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(&pq->array[idx], &pq->array[smallest]);
        siftDown(pq, smallest);
    }
}

void insert(PriorityQueue* pq, int val) {
    if (pq->size == pq->capacity) return; 
    pq->array[pq->size] = val;
    siftUp(pq, pq->size);
    pq->size++;
}

int deleteMin(PriorityQueue* pq) {
    if (pq->size == 0) return -1;
    int root = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    if (pq->size > 0) siftDown(pq, 0);
    return root;
}

int peek(PriorityQueue* pq) {
    if (pq->size == 0) return -1;
    return pq->array[0];
}

int main() {
    int n;
    
    if (scanf("%d", &n) != 1) return 0;

    PriorityQueue* pq = createQueue(n);
    char command[20];

    
    for (int i = 0; i < n; i++) {
        if (scanf("%s", command) != 1) break;

        if (strcmp(command, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(pq, x);
        } else if (strcmp(command, "delete") == 0) {
            printf("%d\n", deleteMin(pq));
        } else if (strcmp(command, "peek") == 0) {
            printf("%d\n", peek(pq));
        }
    }

    free(pq->array);
    free(pq);
    return 0;
}