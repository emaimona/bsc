#include <stdio.h>

int main() {
    int n = 531;
    int ne = 0;
    while (n) {
        ne = ne*10 + n%10;  
        n/=10;
    }

    printf("%d", ne);
}