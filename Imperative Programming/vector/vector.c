#include "vector.h"
#include <stdlib.h>
#include <stdio.h>


bool v_isEmpty(vector* v) {
    return v->size == 0;
}

void v_init(vector* v) {
    v->items = NULL;
    v->length = 0;
    v->size = 0;
}

void v_destroy(vector *v) {
    for (int i=0; i< v->length; i++)
        free(v->items[i]);
    
    free(v->items);
}

void v_insert(vector* v, int val){
    int* data = (int*)malloc(sizeof(int));
    *data = val;

    if (v_isEmpty(v)) {
        v->size++;
        v->items = (int **) malloc(sizeof(int));
    } else if (v->length == v->size) {
        v->size *= 2;
       v->items = (int **) realloc(v->items, sizeof(int*) * v->size);
    }
     v->items[v->length++] = data;


}
int v_size(vector* v) {
    return v->size;
}

int v_length(vector* v) {
    return v->length;
}

void v_delete(vector* v, int val) {

}
