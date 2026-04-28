// //Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.

// Lower Bound: The index of the first element in the array that is greater than or equal to x.
// Upper Bound: The index of the first element in the array that is strictly greater than x.
#include <stdio.h>

int findLowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n; 
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int findUpperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, x;
    
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    if (scanf("%d", &x) != 1) return 0;

    int lb = findLowerBound(arr, n, x);
    int ub = findUpperBound(arr, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}