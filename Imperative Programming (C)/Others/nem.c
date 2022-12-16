#include<stdio.h>

int main() {
    int i=1;
    char a[] = {'2','5','4'};
    char b[] = "Hello";
    while (a[i] != '\0') {
        printf("%s", a);
            i++;
    }
    char *p = a;
    printf("%d\n", a[1]);
    printf("%d %d\n", ++i, ++i);
}