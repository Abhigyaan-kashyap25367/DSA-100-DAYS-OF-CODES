// Problem Statement
// Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.
#include <stdio.h>

int is_feasible(int boards[], int n, int k, int limit) {
    int painters_count = 1;
    int current_sum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > limit) return 0;

        if (current_sum + boards[i] > limit) {
            painters_count++;
            current_sum = boards[i];
            if (painters_count > k) return 0;
        } else {
            current_sum += boards[i];
        }
    }
    return 1;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int boards[n];
    int max_len = 0;
    long long total_sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        if (boards[i] > max_len) max_len = boards[i];
        total_sum += boards[i];
    }

    int low = max_len;
    long long high = total_sum;
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (is_feasible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", result);

    return 0;
}