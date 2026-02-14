//Problem: Write a program to check whether a given square matrix is an Identity Matrix. 
//An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.
#include <stdio.h>

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2) return 0;

    int matrix[r][c];
    int isIdentity = 1;

    if (r != c) {
        isIdentity = 0;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (isIdentity) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i == j) {
                    if (matrix[i][j] != 1) isIdentity = 0;
                } else {
                    if (matrix[i][j] != 0) isIdentity = 0;
                }
            }
        }
    }

    if (isIdentity) {
        printf("The matrix is an Identity Matrix.\n");
    } else {
        printf("The matrix is not an Identity Matrix.\n");
    }

    return 0;
}