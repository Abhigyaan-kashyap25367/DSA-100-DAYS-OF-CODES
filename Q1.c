#include <stdio.h>

int main() {
   
    int n, elementToInsert;
    int i;
    
    printf("Enter the current number of elements : ");
    scanf("%d", &n) ;
   
    int arr[n]; 
    printf("Enter the %d elements (MUST BE SORTED): \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to insert: ");
    scanf("%d", &elementToInsert);

    for (i = n - 1; (i >= 0 && arr[i] > elementToInsert); i--) {
            arr[i + 1] = arr[i]; 
        }
        arr[i + 1] = elementToInsert;
        n++;
        
        printf("Array after insertion (size %d): ", n);
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return 0;
    }