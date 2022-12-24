#include <stdio.h>
#include <stdlib.h>
#include "reverse.h"

int main(int argc, char **argv) {
    FILE* f;

    if (argc != 2) {
        printf("Error: Invalid number of arguments\n");
        return 1;
    } else {
        f = fopen(argv[1], "r");
        if (!f) {
            printf("Error: Cannot open file\n");
            return 1;
        }
    }

    reverse(f);

    return 0;
}
