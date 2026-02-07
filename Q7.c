//Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

#include <stdio.h>
int fibo(int n);

int main(){
    int fibon;
    printf("enter the number ");
    scanf("%d",&fibon);
    printf("series : %d\n",fibo(fibon));
    return 0;
 }
 int fibo(int n){
    int fib;
    for(int i =0;i<=n;i++){
    if (n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
   
    fib=fibo(n-1)+fibo(n-2);
    
 }return fib ;
}