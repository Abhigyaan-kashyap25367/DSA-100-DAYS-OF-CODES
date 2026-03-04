//Problem: Implement push and pop operations on a stack and verify stack operations.
#include <stdio.h>

int main() {
    int n, m, val;
    
    if (scanf("%d", &n) != 1) return 0;
    
    int stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        stack[++top] = val;
    }

    if (scanf("%d", &m) != 1) return 0;

    for (int i = 0; i < m; i++) {
        if (top >= 0) {
            top--;
        }
    }

    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}