#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

void playGame() {
    std::srand(std::time(0));  // Seed random number generator
    int target = std::rand() % 11;  // Random number between 0 and 10
    int guess;

    std::cout << "Guess the number (between 0 and 10): ";

    while (true) {
        std::cin >> guess;

        if (guess < 0 || guess > 10) {
            std::cout << "Please enter a number between 0 and 10: ";
        } else if (guess < target) {
            std::cout << "Too low! Try again: ";
        } else if (guess > target) {
            std::cout << "Too high! Try again: ";
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << target << "\n";
            break;
        }
    }
}

int main() {
    char choice;
    
    do {
        playGame();
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "Thanks for playing!\n";
    return 0;
}