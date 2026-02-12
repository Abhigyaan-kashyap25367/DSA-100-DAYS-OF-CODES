//Problem: Write a program to check whether a given matrix is symmetric.
// A matrix is said to be symmetric if it is a square matrix and is equal to its transpose 
//(i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).
#include <stdio.h>


int main() {
    int rows, cols;
    int isSymmetric = 1;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    
    int matrix[rows][cols];
    
    printf("Enter the matrix elements (%d x %d): \n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (isSymmetric == 0) break;
    }
    
    printf("\nThe matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
    if (isSymmetric==1) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is NOT symmetric.\n");
    }
    
    return 0;
}
