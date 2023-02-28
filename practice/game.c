#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomNumber, guess, numGuesses = 0;
    
    // Generate a random number between 1 and 100
    srand(time(0));
    randomNumber = rand() % 100 + 1;
    
    printf("Guess the number between 1 and 100.\n");
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        numGuesses++;
        
        if (guess > randomNumber) {
            printf("Too high. Try again.\n");
        } else if (guess < randomNumber) {
            printf("Too low. Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d guesses.\n", numGuesses);
        }
    } while (guess != randomNumber);
    
    return 0;
}
