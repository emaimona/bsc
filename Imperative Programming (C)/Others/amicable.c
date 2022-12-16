#include <stdio.h>

int main() {
    int a, b;
    int diva = 1, divb = 1;
    scanf("%d", &a);
    scanf("%d", &b);

    for (int i=2; i<=a/2; i++)
        if (a%i==0)
            diva += i;

    for (int i=2; i<=b/2; i++)
        if (b%i==0)
            divb += i;

    printf("%d", a==divb && b==diva);
    
    return 0;
}