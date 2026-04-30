// Problem Statement
// Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

#include <stdio.h>
#include <stdlib.h>

int canAllocate(int books[], int n, int m, int maxPages) {
    int students = 1;
    int currentPages = 0;
    for (int i = 0; i < n; i++) {
        if (books[i] > maxPages) return 0;
        if (currentPages + books[i] > maxPages) {
            students++;
            currentPages = books[i];
            if (students > m) return 0;
        } else {
            currentPages += books[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    printf("Enter number of books and students: ");
    if (scanf("%d %d", &n, &m) != 2) return 1;

    if (m > n) {
        printf("-1\n");
        return 0;
    }

    int *books = (int *)malloc(n * sizeof(int));
    int sum = 0, maxVal = 0;
    printf("Enter pages in each book: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
        sum += books[i];
        if (books[i] > maxVal) maxVal = books[i];
    }

    int low = maxVal, high = sum;
    int ans = sum;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canAllocate(books, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("Minimum possible value of maximum pages: %d\n", ans);

    free(books);
    return 0;
}