#ifndef REVERSE_H
#define REVERSE_H

#include <stdio.h>
#define INITCAP 8
#define BUFSIZE 1024

char** read(FILE* , char** , int* );
void write(char**, int* );
char* rev(char* );
void reverse(FILE* );
void destroy(char** , int );
int length(char** );
#endif