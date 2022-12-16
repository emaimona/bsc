#include <stdio.h>

int main() {
    for (double fah=-20; fah<=200; fah+=10) {
        double celsius = (fah-32)/1.8;
        printf("%lf -> %lf C\n", fah, celsius);
    }
    return 0;
}