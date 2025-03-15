#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function to play the guessing game
void playGame() {
  int randomNumber, guess, attempts = 0;
  const int maxAttempts = 5;

  // Generate random number
  srand(time(0)); // Seed for random number
  randomNumber = rand() % 10 + 1;

  // Game prompt
  printf("Welcome to the Number Guessing Game!\n");
  printf("I'm thinking of a number between 1 and 10.\n");

  // While attempts is less than 5 you can enter a guess and play
  while (attempts <= maxAttempts) {
    printf("Enter your guess: ");
    scanf("%d", &guess);

    attempts++;

    // Input logic, tells user if guess is too low, high or correct
    if (guess == randomNumber) {
      printf("Congrats! You have gussed the magic number in %d attempts.\n", attempts);
      break;
    } else if (guess < randomNumber) {
      printf("Too low! Try again.\n");
    } else {
      printf("Too high! Try again.\n");
    }
  }
	
  if (attempts > maxAttempts) { // Game over output
 	 printf("Sorry, you've used all %d attempts. The number was %d.\n", maxAttempts, randomNumber);
	}
}

// Function to prompt the user if they want to play again
void newGame() {
	char choice;

	while (1) {  // Loop to keep playing
		playGame(); // Start game

		printf("Would you like to play again? (Y/n): ");
		scanf(" %c", &choice);
		
		if (choice == 'n' || choice == 'N') {
			printf("Thanks for playing!\n");
			break; // exit loop and program
		} else if (choice != 'y' && choice != 'Y') {
			printf("Invalid input.\n");
		}

	} 
}

// Main
int main() {
  newGame(); // Start game loop
  return 0;
  
}
