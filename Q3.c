//Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <stdio.h>

int main() {
    int n, k;
    int comparisons = 0;
    int foundIndex = -1;

    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search for: ");
    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
        comparisons++; 
        if (arr[i] == k) {
            foundIndex = i;
            break; 
        }
    }

    if (foundIndex != -1) {
        printf("Element found at index: %d\n", foundIndex);
    } else {
        printf("Element not found in the array.\n");
    } 
    printf("Total comparisons performed: %d\n", comparisons);

    return 0;
}
