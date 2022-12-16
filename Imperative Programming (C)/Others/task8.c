#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <algorithm.h>
/*8. Given a file, each line of which contains numbers with spaces separated.
   Write a program that reads line by line from this file and writes each row in
   ascending numerical order to a file called output.txt. Manage memory
   dynamically!*/


   
  


int main() {
    FILE* f = fopen("numbers.txt", "r");
    FILE* out = fopen("output.txt","w");
    int sum = 0;
    
    char line[1000];
    while (fgets(line, sizeof(line), f))
    {
        int numbers[100];
        int size = 0;

        char* token = strtok(line, " ");
        sum = 0;
        while (token)
        {
            int n = atoi(token);
            numbers[size++] = n;
            sum += n;
            token = strtok(NULL, " ");
        }

        fprintf(out,"%d\n",sum);
        //sort(numbers, size);

        for (int i = 0; i < size; ++i)
            printf("%d ", numbers[i]);
        printf("\n");
    }

    fclose(f);
    fclose(out);
    return 0;
}