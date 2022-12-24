#ifndef PARITY_ARRAY_H
#define PARITY_ARRAY_H

#define ARRAY_SIZE 10

typedef struct ParityArray {
    int even_idx;
    int odd_idx;
    int size;
    int* array;
} ParityArray;

void init(ParityArray* , int );
void destruct(ParityArray* );
void insert(ParityArray* , int );
void print(ParityArray* );
void dump(ParityArray* , char* );

#endif