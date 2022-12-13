#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"

int main(){
    srand(time(NULL));
    vector v;

    v_init(&v);
    
    for (int i=0; i<5; i++) {
        unsigned int random = (rand() % 100);
        v_insert(&v, random);
    }
         
    for (int i=0; i< v_length(&v); i++) {
        printf("%d  %d\n", i, *v.items[i]);
    }

    printf("The last element is at index %d;\n", v_getIndex(&v, v_top(&v)));
    printf("The vector is empty?: %d;\n", v_isEmpty(&v));
    printf("The vector length is %d;\n", v_length(&v));
    printf("The size of the vector is %d;\n", v_size(&v));

    for (int i=v_length(&v)-1; i >=0 ; i--) {
        printf("Deleting %d  %d\n", i, v_delete(&v, v_top(&v)));
    }

    v_destroy(&v);
    return 0;
}