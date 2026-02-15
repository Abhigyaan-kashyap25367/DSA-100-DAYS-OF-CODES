//Problem: Given a matrix, calculate the sum of its primary diagonal elements.
// The primary diagonal consists of elements where row index equals column index.

#include <stdio.h>


int main() {
    int n;
    int sum = 0;
    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter the matrix elements (%d x %d): \n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    printf("The sum of the main diagonal elements is: %d\n", sum);
    return 0;
}