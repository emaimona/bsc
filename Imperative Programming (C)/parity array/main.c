#include <stdio.h>
#include "parity_array.h"
#include <stdlib.h>

int main() {
    int size;
    ParityArray array;

    printf("Array size: ");
    scanf("%d", &size);

    init(&array, size);

    while (size--) {
        int n;
        printf("Input a number: ");
        scanf("%d", &n);
        insert(&array, n);
    }

    print(&array);
    dump(&array, "out.txt");
    destruct(&array);
    return 0;
}