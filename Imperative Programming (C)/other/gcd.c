#include <stdio.h>

int main() {
    int a=123, b=321;
    int gcd= a<b?a:b;

    /* Brute force
    while (a%gcd!=0 || b%gcd!=0)
        --gcd;
    */

    /* Subtraction method
    while (a!=b)
        if (a<b)
            b-=a;
        else
            a-=b;
    */

    /* Eucleadean */
    while (b!=0) {
        int t=b;
        b=a%b;
        a=t;
    }
    
    printf("%d", a);
}