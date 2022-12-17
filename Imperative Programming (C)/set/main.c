#include <stdio.h>
#include "set.h"


int main(){
    Set set;
    char word[100];
    FILE* file = fopen("main.c", "r");


    while (fgets(word, sizeof(word), file)) {
        insert(&set, word);
        //printf("%s\n", word);
        //fprintf(out, "%s\n", word);
    }
        


    printf("Welcome there are %d unique words\n", set.size);
    fclose(file);
    destroy(&set);

    return 0;
}
