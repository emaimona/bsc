#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define lucky 30
#define MIN 0


int main() {
    int attempts = 3;
    
    srand(time(0));
    int answer = ( rand()% lucky) + MIN;
    int guess;

    do {
        printf("Enter a guess: ");
        scanf("%d", &guess);
        if (guess > answer) {
            printf("Too high!\n");
        } else if (guess < answer) {
            printf("Too low!\n");
        } else {
            printf("Correct\n");
        }

        
        printf("\nAttempts left: %d\n", --attempts);
        
    } while (guess != answer && attempts > 0);

    printf("Game over!\n");
}