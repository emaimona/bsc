#include <stdio.h>
#include "list.h"

int main() {
    List list;
    init(&list);

    prepend(&list, 1);
    for (int i = 2; i < 12; i++ )
        append(&list, i);

    erase(&list, 1);
    erase(&list, 7);
    erase(&list, 11);

    prepend(&list, 0);
    print(&list);
    if (!empty(&list))
        printf("The size of the list is: %d\n", size(&list));
    destroy(&list);
    return 0;
}