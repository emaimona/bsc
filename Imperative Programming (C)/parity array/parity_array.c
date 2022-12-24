#include "parity_array.h"
#include <stdlib.h>
#include <stdio.h>

void init(ParityArray* parr, int size) {
    parr->even_idx = 0;
    parr->odd_idx = size - 1;
    parr->size = size;
    parr->array = (int*) malloc(sizeof(int) * (size));
}


void insert(ParityArray* parr, int value) {
    if (value & 1)
        parr->array[parr->odd_idx--] = value;
    else
        parr->array[parr->even_idx++] = value;
}

void print(ParityArray* parr) {
    int idx = 0;
    while (idx < parr->even_idx)
        printf("%d ", parr->array[idx++]);

    idx = parr->odd_idx + 1;
    while (idx < parr->size)
        printf("%d ", parr->array[idx++]);

    printf("\n");
}

void dump(ParityArray* parr, char* out) {
    FILE* f = fopen(out, "w");

    int idx = 0;
    while (idx < parr->even_idx)
        fprintf(f,"%d ", parr->array[idx++]);

    idx = parr->odd_idx + 1;
    while (idx < parr->size)
        fprintf(f,"%d ", parr->array[idx++]);

    fprintf(f,"\n");
}


void destruct(ParityArray* parr) {
    free(parr->array);
}