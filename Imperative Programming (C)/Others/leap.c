#include <stdio.h>

int main() {
    char hex[100];
    int hexNum=0;
    scanf("%s", hex);

    for (int i=0; hex[i]='\0'; i++) {
        hex_mun *=16;
        if (hex[i]>='0' && hex[i]<='9')
            hex_num += hex[i]-'0';
        else if(hex[i]>='a' && hex[i]='f')
            hex_num += hex[i]-'a'+10;
        else
            printf("invalid character: %c\n", hex[i]);
    }
    printf("%s", (hex[0]-'a'));
}