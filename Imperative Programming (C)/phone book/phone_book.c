#include "phone_book.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void init(PhoneBook* phoneBook, unsigned int capacity) {
    phoneBook->length = 0;
    phoneBook->capacity = capacity;
    phoneBook->items = (contact**)malloc(sizeof(contact*)*capacity);
}

bool insert(PhoneBook* phoneBook, const char name[30], const char phone_number[30]) {
    contact* entry = isContact(phoneBook, name);
    if (entry) {
        strcpy(entry->phone_number, phone_number);
        return true;
    }

    if (phoneBook->length == phoneBook->capacity)
        return false;
    entry = (contact*)malloc(sizeof(contact));
    strcpy(entry->name, name);
    strcpy(entry->phone_number, phone_number);
    phoneBook->items[phoneBook->length++] = entry;

    return true;
}

char* get(PhoneBook* phoneBook, const char name[30]) {
    contact* cont = isContact(phoneBook, name);
    if (cont)
        return cont->phone_number;
    return NULL;
}

contact* isContact(PhoneBook* phoneBook, const char name[30]) {
    for (int i = 0; i < phoneBook->length; i++)
        if (strcmp(phoneBook->items[i]->name, name) == 0)
            return phoneBook->items[i];

    return NULL;
}

void print(PhoneBook* phoneBook) {
    printf("\n*================ PHONE BOOK ENTRIES =================*\n");
    printf("TOTAL: %d\n\n", phoneBook->length);
    for (int i=0; i<phoneBook->length; i++) {
        printf("Contact %d\n", i+1);
        printf("\tName: %s\n\tPhone number: %s\n\n", phoneBook->items[i]->name, phoneBook->items[i]->phone_number);
    }
}

void dump(PhoneBook* phoneBook, char* filename) {
    FILE* output = fopen(filename, "w");
    //for (int i=0; i<phoneBook->items.size(); i++)

    fprintf(output,"\n*================ PHONE BOOK ENTRIES =================*\n\n");
    fprintf(output, "TOTAL: %d\n\n", phoneBook->length);
    for (int i=0; i<phoneBook->length; i++) {
        fprintf(output, "Contact %d\n", i+1);
        fprintf(output,"\tName: %s\n\tPhone number: %s\n\n", phoneBook->items[i]->name, phoneBook->items[i]->phone_number);
    }
    
    fclose(output);
}

void destroy(PhoneBook* phoneBook) {
    for (int i=0; i<phoneBook->length; i++)
        free(phoneBook->items[i]);

    free(phoneBook->items);
}
