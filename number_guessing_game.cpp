#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    char playAgain;

    do {
        // Seeding the random number generator
        srand(time(0));
        int target = rand() % 100 + 1;
        int guess = 0;
        int attempts = 0;

        cout << "Welcome to the Number Guessing Game!" << endl;
        cout << "I have chosen a number between 1 and 100." << endl;
        cout << "Can you guess what it is?" << endl;

        // Loop for guessing the correct number
        do {
            cout << "Enter your guess: ";
            while (!(cin >> guess)) {
                cin.clear(); // clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                cout << "Invalid input. Please enter a number: ";
            }
            attempts++;
            if (guess > target) {
                cout << "Too high! Try again." << endl;
            } else if (guess < target) {
                cout << "Too low! Try again." << endl;
            } else {
                cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
            }
        } while (guess != target);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

