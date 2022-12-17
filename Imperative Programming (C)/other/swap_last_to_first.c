#include <stdio.h>
#include <math.h>

int main() {
    int number;
    scanf("%d", &number);

    int ndigits = log10(number)+1;
    int last = number % 10;
    int rounded = pow(10, ndigits-1);
    int first = number / rounded;

    printf("First %d\n", first);
    
    number -= last;
    number += first;

    number -= first * rounded;
    number += last * rounded;
    
    printf("%d\n", number);
}