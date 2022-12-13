#include <stdio.h>
#include "vector.h"

int main(){
    vector v;

    v_init(&v);
    
    for (int i=0; i<5; i++) 
        v_insert(&v, i);
    
    for (int i=0; i< v_length(&v); i++) {
        printf("%d  %d\n", i, *v.items[i]);
    }
    printf("The vector is empty?: %d;\n", v_isEmpty(&v));
    printf("The vector length is %d;\n", v_length(&v));
    printf("The size of the vector is %d;\n", v_size(&v));


    v_destroy(&v);
    return 0;
}