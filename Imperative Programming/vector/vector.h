#ifndef VECTOR_H
#define VECTOR_H
#include <stdbool.h>

typedef struct vector {
    int** items;
    int size;
    int length;
} vector;

void v_init(vector*);
void v_insert(vector*, int);
int v_size(vector*);
int v_length(vector*);
void v_delete(vector*, int);
bool v_isEmpty(vector*);
void v_destroy(vector*);
#endif