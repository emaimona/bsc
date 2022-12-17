#include <stdio.h>
#include <stdlib.h>

int main(int arg, char* args[]) {

    int num = atoi(args[1]);
    printf("%d \n", num);
    
    char** arr = (char**)malloc(sizeof(char*)*num);
    int i=0;
    while (num--) {
        arr[i] = (char*)malloc(200);
        scanf("%s", arr[i]);
        printf("\n%s\n", arr[i]);
        
        if (!strcmp(arr[i], "end")) {
            break;
        }
    }

    return 0;
}