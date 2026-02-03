//Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.
#include <stdio.h>
int main() {
    int n, pos, x, i;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n + 1];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the 1-based position to insert at: ");
    scanf("%d", &pos);

    printf("Enter the element to insert: ");
    scanf("%d", &x);
   
    for (i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x;
    n++;

    printf("Array after insertion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
