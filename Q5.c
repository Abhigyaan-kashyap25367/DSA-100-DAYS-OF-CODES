//Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int p, q;

    printf("Enter the number of entries for the FIRST server: ");
    scanf("%d", &p);

    int *log1 = (int *)malloc(p * sizeof(int));
    printf("Enter the %d sorted arrival times (separated by spaces): ", p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    printf("\nEnter the number of entries for the SECOND server: ");
    if (scanf("%d", &q) != 1) return 1;

    int *log2 = (int *)malloc(q * sizeof(int));
    printf("Step 4: Enter the %d sorted arrival times (separated by spaces): ", q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    printf("\n Final Chronological Log \n");
    int i = 0, j = 0;
    int first = 1;

    while (i < p && j < q) {
        if (!first) printf(" ");
        if (log1[i] < log2[j]) {
            printf("%d", log1[i++]);
        } else {
            printf("%d", log2[j++]);
        }
        first = 0;
    }

    while (i < p) {
        if (!first) printf(" ");
        printf("%d", log1[i++]);
        first = 0;
    }

    while (j < q) {
        if (!first) printf(" ");
        printf("%d", log2[j++]);
        first = 0;
    }

    

    free(log1);
    free(log2);

    return 0;
}
