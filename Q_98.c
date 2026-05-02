// Problem: Given intervals, merge all overlapping ones.
// Sort first, then compare with previous.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compareIntervals(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

void mergeIntervals(Interval arr[], int n) {
    if (n <= 0) return;

    qsort(arr, n, sizeof(Interval), compareIntervals);

    int index = 0;

    for (int i = 1; i < n; i++) {
        if (arr[index].end >= arr[i].start) {
            if (arr[index].end < arr[i].end) {
                arr[index].end = arr[i].end;
            }
        } else {
            index++;
            arr[index] = arr[i];
        }
    }

    printf("Merged Intervals: ");
    for (int i = 0; i <= index; i++) {
        printf("[%d, %d] ", arr[i].start, arr[i].end);
    }
}

int main() {
    Interval arr[] = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}