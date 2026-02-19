//Problem: Given an array of integers, rotate the array to the right by k positions.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, temp, start, end;

    printf("Enter the size of array =");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of array = ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter k = ");
    scanf("%d", &k);

    k = k % n;

    if (k > 0) {
        start = 0;
        end = n - 1;
        while (start < end) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }

        start = 0;
        end = k - 1;
        while (start < end) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }

        start = k;
        end = n - 1;
        while (start < end) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    printf("Result = ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}