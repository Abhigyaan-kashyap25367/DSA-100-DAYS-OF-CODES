//Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    long long count = 0;
    for (int i = 0; i < n; i++) {
        long long current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            if (current_sum == 0) {
                count++;
            }
        }
    }

    printf("%lld\n", count);

    return 0;
}