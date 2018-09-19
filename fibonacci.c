#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) 
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n > 1)  
        return fibonacci(n -1) + fibonacci(n - 2);
}

typedef struct pair {
    int a, b;
} pair;

pair linearFibonacci(int n) 
{
   if (n == 1) 
       return (pair) {n ,0};
   else {
       pair p1 = linearFibonacci(n - 1);
       return (pair) {p1.a + p1.b, p1.a};
   }
}

int iterativeFibonacci(int n)
{
    int a = 1, b = 0, prevB;
    for (int i = 2; i <= n; ++i) {
       prevB = b;
       b = a;
       a = prevB + a;
    }
    return a;
}

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);
    printf("recursive:%d\n", fibonacci(n));
    printf("linear:%d\n", linearFibonacci(n).a);
    printf("iterative:%d\n", iterativeFibonacci(n));
    return 0;
}
