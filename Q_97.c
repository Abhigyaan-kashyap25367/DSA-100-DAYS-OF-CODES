// Problem: Given meeting intervals, find minimum number of rooms required.
// Sort by start time and use min-heap on end times.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compareIntervals(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeapify(heap, size, smallest);
    }
}

void pushHeap(int heap[], int* size, int val) {
    heap[*size] = val;
    int i = (*size)++;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void popHeap(int heap[], int* size) {
    heap[0] = heap[--(*size)];
    minHeapify(heap, *size, 0);
}

int minMeetingRooms(Interval* intervals, int n) {
    if (n == 0) return 0;

    qsort(intervals, n, sizeof(Interval), compareIntervals);

    int* heap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;

    pushHeap(heap, &heapSize, intervals[0].end);

    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= heap[0]) {
            popHeap(heap, &heapSize);
        }
        pushHeap(heap, &heapSize, intervals[i].end);
    }

    free(heap);
    return heapSize;
}

int main() {
    Interval meetings[] = {{0, 30}, {5, 10}, {15, 20}};
    int n = sizeof(meetings) / sizeof(meetings[0]);
    printf("Minimum rooms required: %d\n", minMeetingRooms(meetings, n));
    return 0;
}