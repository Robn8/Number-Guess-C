#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int generate_random_number(int max) {
  srand(time(NULL)); // Seed the random number generator
  return rand() % max + 1; // Random number between 1 and max
  
}

// Function to play the guessing game
void play_game(int max_attempts, int max_number) {
  // Generate random number
  int secret_number = generate_random_number(max_number);
  // Set initial guesses to 0
  int guess, attempts = 0;

  // Game prompt
  printf("Welcome to the Number Guessing Game!\n");
  printf("I'm thinking of a number between 1 and %d.\n", max_number);

  // While attempts is less than 5 you can enter a guess and play
  while (attempts < max_attempts) {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    attempts++;

    // Input logic, tells user if guess is too low, high or correct
    if (guess < secret_number) {
      printf("Too low! Try again.\n");
    } else if (guess > secret_number) {
      printf("Too high! Try again.\n");
    } else {
      printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
      return;
    }
  }

  // Game over output
  printf("Sorry, you've used all your attempts. The number was %d.\n", secret_number);
}

// Main
int main() {
  int max_attempts = 5; // Attempts for user
  int max_number = 50; // Set guess range

  play_game(max_attempts, max_number); // Pass variables into play_game function

  return 0;
  
}
