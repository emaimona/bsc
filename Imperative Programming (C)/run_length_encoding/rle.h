#ifndef RLE_H
#define RLE_H

#define BUFFER_SIZE 1024

typedef struct Pair {
    char c;
    int n;
} Pair; 

typedef struct Encoded {
    int length;
    Pair** arr;
} Encoded;

Encoded* encode(const char* );
char* decode(Encoded* );
void addPair(Encoded* , Pair*);
char* toString(Encoded* );
void destroy(Encoded* );
#endif