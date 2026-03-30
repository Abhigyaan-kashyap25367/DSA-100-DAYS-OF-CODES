//Problem Statement: Implement a Min Heap using an array where the smallest element is always at the root.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int cap) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->data = (int*)malloc(cap * sizeof(int));
    h->size = 0;
    h->capacity = cap;
    return h;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(MinHeap* h, int x) {
    if (h->size == h->capacity) {
        printf("Heap Overflow\n");
        return;
    }
    int i = h->size++;
    h->data[i] = x;
    while (i != 0 && h->data[(i - 1) / 2] > h->data[i]) {
        swap(&h->data[i], &h->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void minHeapify(MinHeap* h, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < h->size && h->data[l] < h->data[smallest]) smallest = l;
    if (r < h->size && h->data[r] < h->data[smallest]) smallest = r;
    if (smallest != i) {
        swap(&h->data[i], &h->data[smallest]);
        minHeapify(h, smallest);
    }
}

int extractMin(MinHeap* h) {
    if (h->size <= 0) return -1;
    if (h->size == 1) return h->data[--h->size];
    int root = h->data[0];
    h->data[0] = h->data[--h->size];
    minHeapify(h, 0);
    return root;
}

int peek(MinHeap* h) {
    return (h->size <= 0) ? -1 : h->data[0];
}

void display(MinHeap* h) {
    if (h->size == 0) { printf("Heap is empty\n"); return; }
    printf("Heap Array: ");
    for (int i = 0; i < h->size; i++) printf("%d ", h->data[i]);
    printf("\n");
}

int main() {
    int capacity, choice, val;
    printf("Enter maximum heap capacity: ");
    scanf("%d", &capacity);
    MinHeap* h = createHeap(capacity);

    printf("\n--- Instructions ---\n");
    printf("1. Insert x\n2. Extract Min\n3. Peek\n4. Display Heap\n5. Exit\n");

    while (1) {
        printf("\nChoice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(h, val);
                break;
            case 2:
                val = extractMin(h);
                if (val == -1) printf("-1\n");
                else printf("Extracted: %d\n", val);
                break;
            case 3:
                val = peek(h);
                if (val == -1) printf("-1\n");
                else printf("Min: %d\n", val);
                break;
            case 4:
                display(h);
                break;
            case 5:
                free(h->data);
                free(h);
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}