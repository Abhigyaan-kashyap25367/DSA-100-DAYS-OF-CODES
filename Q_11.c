//Problem: Write a program to perform addition of two matrices having the same dimensions.
// The sum of two matrices is obtained by adding corresponding elements of the matrices.

#include <stdio.h>
int main() {
    int rows, cols, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    
    int matA[rows][cols];
    int matB[rows][cols];
    
    printf("Enter elements of Matrix A (%d x %d): \n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matA[i][j]);
        }
    }
    
    printf("Enter elements of Matrix B (%d x %d): \n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matB[i][j]);
        }
    }
    int result[rows][cols];
    printf("Result Matrix (A + B):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}