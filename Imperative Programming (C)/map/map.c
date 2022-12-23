#include "map.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void init(Map* map) {
    map->size = 0;
    map->items = NULL;
}

void dest(Map* map) {
    for (int i=0; i<map->size; i++) 
        free(map->items[i]);
    
    free(map->items);
}

Pair* find(Map* map, const char* str) {
    for (int i=0; i<map->size; i++) {
        if (strcmp(map->items[i]->str, str) == 0)
            return map->items[i];
    }

    return NULL;
}

Pair* makePair(const char* str, int num) {
    Pair* pair = (Pair*) malloc(sizeof(Pair));
    strcpy(pair->str, str);
    pair->num = num;

    return pair;
}

void set(Map* map, const char* str, int num) {
    Pair* pair = find(map, str);
    
    if (pair) {
        pair->num = num;
    } else {
        pair = makePair(str, num);
        map->items = (Pair**)realloc(map->items, sizeof(Pair*) * (map->size + 1));
        map->items[map->size++] = pair;
    }
}

int get(Map* map, const char* str) {
    Pair* pair = find(map, str);

    if (pair)
        return pair->num;
    
    set(map, str, 0);
    return 0;
}

void print(Map* map) {
    printf("\n============ OUTPUT ============ \n\n");

    for (int i=0; i<map->size; i++)
        printf("%s -> %d\n", map->items[i]->str, map->items[i]->num);
    
    printf("\n");
}
