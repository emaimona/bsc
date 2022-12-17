#ifndef SET_H
#define SET_H

#include <stdbool.h>

typedef struct Set {
    int size;
    char* items[100];
} Set;

bool contains(Set*, const char*);
void init(Set*);
void delete(Set*, const char*);
void destroy(Set*);
void erase(Set*, int);
void insert(Set*, const char*);


#endif
