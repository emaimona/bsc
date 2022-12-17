#include<stdio.h>

int main() {

    int i = 2;
    int j = i-- - --i;
    printf("%d\n", j);
    return 0;
}