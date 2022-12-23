#include "rle.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Encoded* encode(const char* str) {
    Encoded* code = (Encoded*) malloc(sizeof(Encoded));
    code->length = 0;
    code->arr = NULL;

    int count = 1;
    char c = str[0];
    for (int i=1; i<strlen(str); i++) {
        if (c != str[i]) {
            Pair* pair = (Pair*) malloc(sizeof(Pair));
            pair->c = c;
            pair->n = count;
            addPair(code, pair);

            c = str[i];
            count = 0;
        } 

        count++; 
    }

    Pair* pair = (Pair*) malloc(sizeof(Pair));
    pair->c = str[strlen(str) - 1];
    pair->n = count;
    addPair(code, pair);

    return code;
}


void addPair(Encoded* code, Pair* pair) {
    code->arr = (Pair**) realloc(code->arr, sizeof(Pair*) * (code->length + 1));
    code->arr[code->length++] = pair;
}

char* decode(Encoded* code) {
    static char str[BUFFER_SIZE];
    strcpy(str, "");

    for (int i=0; i<code->length; i++) {
        int count = code->arr[i]->n;
        char c[2];
        sprintf(c, "%c", code->arr[i]->c);
        while (count--)
            strcat(str, c);
    }
    return str;
}

char* toString(Encoded* code) {
    static char str[BUFFER_SIZE];
    strcpy(str, "");

    for (int i=0; i<code->length; i++) {
        char s[3];
        sprintf(s, "%c%d", code->arr[i]->c, code->arr[i]->n);
        strcat(str, s);
    }
    return str;
}


void destroy(Encoded* code) {
    for (int i=0; i<code->length; i++)
        free(code->arr[i]);
    free(code->arr);
}