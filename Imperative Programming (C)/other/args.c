#include <stdio.h>
#include <stdlib.h>

// Read a number from the command line and read n times a string
int main(int arg, char* args[]) {
    if (arg != 2) {
        printf("One command-line argument is needed!\n");
        return 1;
    }
    int num = atoi(args[1]);
    char **words2 = (char**)malloc(sizeof(char*) * num);
    for (int i=0; i<num; ++i) {
        words2[i] = (char*)malloc(20);
        scanf("%s", words2[i]);
    }

    for (int i=0; i<num; ++i) {
        printf("%s\n", words2[num - i - 1]);
    }

    for (int i=0; i<num; ++i)
        free(words2[i]);

    free(words2);
    return 0;
}