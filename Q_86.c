// Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

#include <stdio.h>

long long integerSquareRoot(int n) {
    if (n < 2) return n;

    long long low = 0, high = n;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;

        if (square == n) {
            return mid;
        } else if (square < n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    printf("%lld\n", integerSquareRoot(n));

    return 0;
}