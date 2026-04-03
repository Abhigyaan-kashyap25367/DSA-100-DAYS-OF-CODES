// Problem Statement:
// Check whether a given binary tree satisfies the Min-Heap property.
#include <stdio.h>
#include <stdlib.h>

int main() {
int n;
if (scanf("%d", &n) != 1) return 0;

int *arr = (int *)malloc(n * sizeof(int));
for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
}

int is_min_heap = 1;
for (int i = 0; i <= (n - 2) / 2; i++) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[i] > arr[left]) {
        is_min_heap = 0;
        break;
    }
    if (right < n && arr[i] > arr[right]) {
        is_min_heap = 0;
        break;
    }
}

if (is_min_heap) {
    printf("YES\n");
} else {
    printf("NO\n");
}

free(arr);
return 0;
}