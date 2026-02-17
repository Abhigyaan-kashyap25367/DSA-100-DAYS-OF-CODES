//Problem: Write a program to find the maximum and minimum values present in a given array of integers.

#include<stdio.h>
int main(){
    int n;
    printf("enter the number =");
    scanf("%d",&n);
    int arr[n];
    
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int largest=arr[0];
    int smallest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
        if(arr[i]<smallest){
            smallest=arr[i];

        }
    }

    printf("LARGEST NUMBER IS %d\n",largest);
    printf("SMALLEST NUMBER IS %d\n",smallest);
    return 0;
}
