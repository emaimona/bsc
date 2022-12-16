#include <stdio.h>
//#include 

int main()  {
    FILE * f = fopen("f.text", "r");
    char line[1024];

    int length; 
    while (fgets(line, sizeof(line), f)) {
        length = strlen(line);
        for (int i=0; i<length; i++) {
            printf("%c", toupper(line[i]));
        }
    }
    fclose(f);

    return 0;
}