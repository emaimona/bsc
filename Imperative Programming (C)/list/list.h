#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* first;
    Node* last;
    int size;
} List;

void append(List*, int);
void destroy(List*);
bool empty(List*);
void erase(List*, int);
Node* getNode(int, Node* next);
void init(List*);
void prepend(List*, int);
void print(List*);
int size(const List* );

#endif