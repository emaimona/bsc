#ifndef MAP_H
#define MAP_H\

#define WORD_BUFFER_SIZE 32

typedef struct Pair {
    char str[WORD_BUFFER_SIZE];
    int num;
} Pair;

typedef struct Map {
    Pair** items;
    int size;
} Map;

void init(Map* );
void dest(Map* );
Pair* find(Map* , const char* );
Pair* makePair(const char* , int );
void set(Map* , const char* , int );
int get(Map* , const char* );
void print(Map* );


#endif
