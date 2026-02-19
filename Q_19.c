#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter the size of Array = ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of Array = ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int left = 0;
    int right = n - 1;
    int min_sum = INT_MAX;
    int res_l = 0;
    int res_r = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        
        int abs_sum = (sum < 0) ? -sum : sum;
        int abs_min = (min_sum < 0) ? -min_sum : min_sum;

        if (abs_sum < abs_min) {
            min_sum = sum;
            res_l = left;
            res_r = right;
        }

        if (sum < 0) {
            left++;
        } else if (sum > 0) {
            right--;
        } else {
            break;
        }
    }

    printf("%d %d\n", arr[res_l], arr[res_r]);

    free(arr);
    return 0;
}