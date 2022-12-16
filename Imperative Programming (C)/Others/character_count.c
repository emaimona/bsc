#include <stdio.h>

int main() {
    char word[900];
    int counter[27] = {0};

    printf("\nInput a string: " );
    if(scanf("%[^\n]%*c", word)){}; 
    
    for (int i=0; word[i] !='\0'; i++) {
        if (word[i] == ' ') {
            counter[26] +=1;
            continue;
        }
        
        int index = word[i]-'a'; 
        if (!(index>=0 && index<=26))
            index = word[i]-'A';
        counter[index] += 1;
    }

    printf("\nThe character count of the chars are: \n");
    for (int i=0; i<26; i++) {
        printf("%c => %d\n", (i+'a'), counter[i]);
    }
    printf("\nSpaces: %d", counter[26]);
    printf("\n");
    
    return 0;
}