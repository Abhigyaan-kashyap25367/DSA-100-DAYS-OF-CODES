//Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    if (scanf("%d", &n) != 1) return 0;

    int *queue = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    scanf("%d", &m);

    
    for (int i = 0; i < n; i++) {
        int index = (m + i) % n;
        printf("%d", queue[index]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    free(queue);
    return 0;
}