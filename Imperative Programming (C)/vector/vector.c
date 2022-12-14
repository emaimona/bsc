#include "vector.h"
#include <stdlib.h>
#include <stdio.h>


bool v_isEmpty(vector* v) {
    return v->length == 0;
}

void v_init(vector* v) {
    v->items = NULL;
    v->length = 0;
    v->size = 0;
}

void v_destroy(vector *v) {
    free(v->items);
}

void v_insert(vector* v, int val){
    if (v_isEmpty(v)) {
        v->size++;
        v->items = (int *) malloc(sizeof(int));
    } else if (v->length == v->size) {
        v->size *= 2;
       v->items = (int *) realloc(v->items, sizeof(int) * v->size);
    }
     v->items[v->length++] = val;


}
int v_size(vector* v) {
    return v->size;
}

int v_length(vector* v) {
    return v->length;
}

int v_top(vector* v) {
    if (!v_isEmpty(v))
        return v->items[v->length-1];

    return INT16_MIN;  
}

int v_getIndex(vector* v, int val) {
    for (int i=0; i<v->length; i++) {
        if (v->items[i] == val)
            return i;
    }

    return -1;
}

int v_delete(vector* v, int val) {
    int index = v_getIndex(v, val);
    if (index < 0)
        return INT16_MIN; 

    for (int i=index+1; i<v->length; i++) {
        v->items[i-1] = v->items[i];
    }
    v_pop(v);
    return val;
}

int v_pop(vector* v) {
    if (!v_isEmpty(v)) {
        int val = v->items[--v->length];
        return val;
    }
    return INT16_MIN;
}