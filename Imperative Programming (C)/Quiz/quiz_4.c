#include<stdio.h>
#include<string.h>

int main() {
    char str[10000];
    scanf("%[^\n]", str);

    int i = 0;
    int j = strlen(str)-1;

    while (i<j) {
        if (str[i++] != str[j--]) {
            printf("%s is not palindrome!\n", str);
            return 0;
        }
    }

    printf("%s is a palindrome!\n", str);
    
    return 0;
}