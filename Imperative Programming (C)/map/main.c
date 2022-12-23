#include <stdio.h>
#include <string.h>
#include "map.h"


int main() {
    Map map;
    init(&map);
    char words[1024];

    FILE* file = fopen("input.txt", "r");
    while(fgets(words, sizeof(char)*1024, file)) {
        char* word = strtok(words, " ");
        while (word) {
            int idx = strlen(word)-1;
            if (word[idx] == '\n')
                word[idx] = '\0';

            int num = get(&map, word);
            set(&map, word, num + 1);
            word = strtok(NULL, " ");
        }

    }

    printf("\nSize of map: %d\n", map.size);


    print(&map);
    dest(&map);
    return 0;
}