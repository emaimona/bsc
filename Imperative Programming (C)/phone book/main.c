#include <stdio.h>
#include "phone_book.h"

int main() {
    char* filename = "output.txt";
    bool res = false;
    char* name = NULL;

    PhoneBook phoneBook;
    init(&phoneBook, 3);
    
    insert(&phoneBook, "Emanuel", "97453452");
    insert(&phoneBook, "Maimona", "34523452");
    insert(&phoneBook, "Joseph", "83452452");

    res = insert(&phoneBook, "Bodri", "53452452");
    printf("\nWas the insertion of entry \"Bodri\" successful? %s \n", \
             (res == 0)? "No": "Yes");

    res = insert(&phoneBook, "Maimona", "53452452");
    printf("\nWas the update of entry \"Maimona\" successful? %s \n", \
             (res == 0)? "No": "Yes");

    name = "emanuel";
    printf("\nPrint the entry with the name %s => Phone number: %s\n", name, get(&phoneBook, name));

    name = "Emanuel";
    printf("\nPrint the enttry with the name %s => Phone number: %s\n", name, get(&phoneBook, name));

    dump(&phoneBook, filename);
    print(&phoneBook);
    destroy(&phoneBook);
    return 0;
}