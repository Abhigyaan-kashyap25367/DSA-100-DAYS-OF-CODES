//Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *queue = (int *)malloc(n * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        
        
        queue[rear] = val;
        rear++;
    }

    
    for (int i = front; i < rear; i++) {
        printf("%d", queue[i]);
        if (i < rear - 1) {
            printf(" ");
        }
    }

    free(queue);
    return 0;
}