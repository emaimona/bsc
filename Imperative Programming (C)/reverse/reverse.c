#include "reverse.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char** read(FILE* f, char** string, int* ISize) {
    int count = 0;
    static char str[BUFSIZE];
    strcpy(str, "");

    while (fgets(str, sizeof(char) * BUFSIZE, f)) {
        if (count == *ISize) {
            *ISize = (*ISize <= 0) ? 2 : (*ISize) * 2;
            string = (char**)realloc(string, sizeof(char*)*(*ISize));
        }
        
        char* s = (char*)malloc(sizeof(char)*BUFSIZE);
        strcpy(s, str);
        string[count++] = s;
    }

    return string;
}

char* rev(char* string) {
    int i = 0;
    int s = strlen(string)-1;

    while (i < strlen(string)/2) {
        char c = string[i];
        string[i] = string[s];
        string[s] = c;
        i++; s--;
    }

    return string;
}

int length(char **str) {
    int i = 0;
    while (str[i] != NULL)
        i++;
    return i;
}


void write(char** string, int* ISize) {
    int count = length(string);
    static char str[BUFSIZE];
    strcpy(str, "");

    while (count > -1) {
        if (string[count]) {
            // adding \n
            //strcpy(str, rev(string[count]));
            // if (str[0] == '\n')
            //     sprintf(str, "%s", str+1);
            //rev(string[count]); // Get back the string
            printf("%d %s\n", --count+1, str);
        }
    }

    
}

void reverse(FILE* f) {
    int len = INITCAP;
    char** string = (char**) malloc(sizeof(char*) * len);
    read(f, string, &len);
    write(string, &len);

    destroy(string, len);
}

void destroy(char** string, int len) {
    int i=0;

    // while (string[i])
    //     free(string[i++]);

    free(string);
}