#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define SQR(x) x * x

union car {
    char* name;
    int age;

};

int main(void) {
    char str [] = {'d','d','d'};
    char me[] = "kklsd";
    bool v = -44;
    int matrix[3][5];
    int t[] = {1,3,5, 6};
    int (*jk)[4] = &t;
    union car m = {19, "Hello"};
    printf(me);
    printf("%lu %d\n", sizeof(m), m.name);
    printf("%d\n", SQR(3+2));
    
    char good[] = "good";
    char bad[] = {'b','a','d','\0'};
    char ugly[] = {'u','g','l','y','\0'};
    printf("%s %s %s\n", good, bad, ugly);

    
    
    printf("%s \n", ("helloWorld"+5)+5);
    printf("%d \n", 2);
    int i=0;
    while (str[i] != 0) {
        //printf("%c", str[i]);
        i++;
    }
    // unsigned int i = 0;
    // _Bool v = 0.4;
    // //char s[] = {'a', '3'};
    // int n=4, s;

    // for (int i=0; i<5; i++) {
    //     for (int j=0; j<5; n++) {
    //         break;
    //         break;
    //     }
    //     printf("fdd\n");
    // }
    
    // printf("Left shift: %d\n", (~i)>>1);
    // printf("Max int: %d", ~((~i)>>1));
    // printf("\nSomething: %d", 011|0);
    // //printf("\nApple: %luasd\n", sizeof(size_t));
    // //printf("%lu\n", sizeof(s)/sizeof(s[0]));
    return 0;
}