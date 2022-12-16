#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void append(List* list, int val) {
    Node* node = getNode(val, NULL);
    if (empty(list))
        list->first = node;
    else
        list->last->next = node;


    list->last = node;
    list->size++;
}

void destroy(List* list) {
    Node* node = list->first;
    Node* ptr;

    while (node) {
        ptr = node;
        node = node->next;
        free(ptr);
    }
}

bool empty(List* list) {
    return list->size == 0;
}

void erase(List* list, int val) {
    Node* node = list->first;
    Node* prev = NULL;
    
    while (node && node->data != val) {
        prev = node;
        node = node->next;
    }

    if (!node)
        return;

    if (prev && node)
        prev->next = node->next;

    if (list->first == node)
        list->first = node->next;

    if (list->last == node)
        list->last = prev;

    free(node);
    list->size--; 
}

Node* getNode(int val, Node* next) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = val;
    node->next = next;
    return node;
}

void init(List* list) {
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
}
void prepend(List* list, int val) {
    Node* node = getNode(val, list->first);
    if (empty(list))
        list->last = node;
        
    list->first = node;
    list->size++;
}

void print(List* list) {
    for (Node* node = list->first; node; node = node->next) 
        printf("Node (%d) -> ", node->data);

    printf("\n");
}

int size(const List* list) {
    return list->size;
}