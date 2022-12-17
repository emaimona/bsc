#include <stdio.h>
#include <stdbool.h>


int main() {
    int u = 1;
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(long int));
    printf("%lu\n", sizeof(_Bool));
    printf("%lu\n", ~u|1);
    return 0;
}