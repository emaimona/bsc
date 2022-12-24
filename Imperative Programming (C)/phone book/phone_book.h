#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <stdbool.h>

typedef struct contact {
    char name[30];
    char phone_number[30];
} contact;

typedef struct PhoneBook {
    contact** items;
    unsigned int length;
    unsigned int capacity;
} PhoneBook;

void init(PhoneBook* , unsigned int);
bool insert(PhoneBook* , const char[], const char[]);
char* get(PhoneBook* , const char[]);
void print(PhoneBook*);
void dump(PhoneBook*, char*);
void destroy(PhoneBook*);

contact* isContact(PhoneBook*, const char[]);

#endif
