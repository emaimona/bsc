#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "rle.h"

bool isNotOkay(const char *input) {
    int i = 0;

    while (input[i])
        if (isupper(input[i++]))
            return true;

    return false;
}

int main(int argc, char** argv) {

    if (argc != 2 || isNotOkay(argv[1])) {
        printf("Bad Input!\n");
        return 1;
    }

    Encoded* code = encode(argv[1]);
   
    printf("\ninput: %s", argv[1]);
    printf("\noutput: %s -> %s\n\n", toString(code), decode(code));
  
    return 0;
}