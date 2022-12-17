#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mycopy(char *copy, char *str) {
    int i = 0;
    while (str[i] != '\0') {
        copy[i] = str[i];
        i++;
    }
    copy[i] = '\0';
}

void mreverse(char* copy) {
    int i = 0;
    int j = strlen(copy) - 1;
   
    while (i<j) {
        char temp = copy[i];
        copy[i] = copy[j];
        copy[j] = temp;
        i++; j--;
    }
}

int main() {
    char str[20];

    scanf("%[^\n]s", str);
    char* copy = (char*)malloc(strlen(str) + 1);
    
    //mycopy(copy, str);
    strcpy(copy, str);
    printf("\n The copy is: %s\n", copy);

    //reverse(copystr);
    mreverse(copy);
    printf("\nReversed: %s\n", copy);
    
    free(copy);
    return 0;
}