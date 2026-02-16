//Problem: Given an array of integers, count the frequency of each distinct element and print the result.
#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of array =");
    scanf("%d", &n);

    int arr[n];
    int visited[n];
    printf("Enter the %d elements \n",n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) {
            continue;
        }
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        } 
        printf("%d:%d", arr[i], count);
        if (i < n - 1) {
            printf(" ");
        }
    }
    return 0;
}