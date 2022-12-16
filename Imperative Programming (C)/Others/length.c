#include<stdio.h>

int main() {
    char str[999];
    int count = 0;
    scanf("%[^\n]s", str);

    for (int i=0; str[i] != '\0'; i++);

    printf("\nThe size of the string is: %d\n", i);
    return 0;
}