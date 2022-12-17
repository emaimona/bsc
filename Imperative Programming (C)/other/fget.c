#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {

    char str[1024];
    fgets(str, sizeof(str), stdin); // use if == NULL to get rid of the warning

    int length = strlen(str);
    printf("Number of characters: %d\n", length);

    if (length == 1)
        return 0;

    int word = 1;

    for (int i=1; i<length; i++) {
        if ((str[i]==' ' && str[i-1] !=' ')) 
            word++;
    }
    printf("Number of words %d: \n", word);

    double t = 4.8;
    int *p = NULL;
    double *d = &t;

    printf("Size of int %ld \n size of double %ld \n", sizeof(p), sizeof(d));
    
    
}