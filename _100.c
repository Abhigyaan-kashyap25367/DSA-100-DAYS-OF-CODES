// Problem: For each element, count how many smaller elements appear on right side.
// Use merge sort technique or Fenwick Tree (BIT).

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Element;

void merge(Element arr[], int left, int mid, int right, int count[]) {
    int i = left, j = mid + 1, k = 0;
    int right_smaller_count = 0;
    Element* temp = (Element*)malloc((right - left + 1) * sizeof(Element));

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            right_smaller_count++;
            temp[k++] = arr[j++];
        } else {
            count[arr[i].index] += right_smaller_count;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += right_smaller_count;
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
    free(temp);
}

void mergeSort(Element arr[], int left, int right, int count[]) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);
        merge(arr, left, mid, right, count);
    }
}
