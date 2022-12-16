#include <stdio.h>

long long unsigned factorial(long long unsigned n, long long unsigned next) {
    if (n<2)
        return next;

    return factorial(n-1, n*next);
}

int fib(int a, int b, int n) {
    if (n==0)
        return a;
    return fib(b, a+b, n-1);
}

int main() {
    for (int i=0; i<10; i++)
        printf("Factorial of %d = %d\n", i, fib(0,1,i));

    return 0;
}