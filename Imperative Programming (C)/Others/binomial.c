#include <stdio.h>

long long binomial(int n, int r) {
    
    long long num = 1;
    long long den = 1; 

    for (int x=0; x<r; x++) {
        num *= n-x;
        den *= x+1;
    }
    return num/den;
}

int main() {
    int n;
    printf("Input the n: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            printf("%lld ", binomial(i,j));
        }
        printf("\n");
    }
    
    return 0;
}