#include <stdio.h>
#include <math.h>

void divisors(int n, int d, int root) {
    if (d > root)
        return;
    
    if (n%d==0)
        printf("%d ", d);

    divisors(n, d+1, root);
    
    if (n/d != d)
        printf("%d ", n/d);
}

int main() {
    int n;
    
    scanf("%d",&n);
    divisors(n, 1, (int)sqrt(n));

    return 0;
}