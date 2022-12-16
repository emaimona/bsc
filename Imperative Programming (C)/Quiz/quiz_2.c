#include<stdio.h>

int convert(char nbr[]) {
    int newnbr = 0;

    for (int i=0; nbr[i]; i++) {
        newnbr = newnbr*10 + (nbr[i]-'0');
    }
    return newnbr;
}

int main() {
    char number[1000];

    scanf("%s", number);
    printf("%d\n", convert(number));
    
    return 0;
}