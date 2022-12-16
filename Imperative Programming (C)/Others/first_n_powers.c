#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int x = n;

    for (int i=1; i<=n; i++) {
        printf("%d ^ %d = %d \n", n, i, x);
        x *= n;
    }

    
    return 0;
}