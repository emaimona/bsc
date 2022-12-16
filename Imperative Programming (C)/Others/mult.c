#include <stdio.h>

int main() {

    for (int i=2; i<11; i++) {
        for (int j=1; j<11; j++)
            printf("%d * %d = %d\n", i, j, i*j);
        printf("\n");
    }
}