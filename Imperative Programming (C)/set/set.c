#include "set.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


bool contains(Set* s, const char* str) {
    for (int i = 0; i < s->size; i++) {
        if (strcmp(str, s->items[i]) == 0) {
            return true;
        }
    }
    return false;
}


void init(Set* s) {
    s->size = 0;
}

void insert(Set* s, const char* str) {
    if (contains(s, str))
        return;

    char* word = (char*)malloc(sizeof(char)*strlen(str)+1);
    strcpy(word, str);
    s->items[s->size++] = word;
}

void delete(Set* s, const char* str) {

}

void destroy(Set* s) {
    for (int i=0; i<s->size; i++)
        free(s->items[i]);
}
