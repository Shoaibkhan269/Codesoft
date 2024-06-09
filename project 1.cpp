#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    int randomNumber = dis(gen);
    int guess = 0;

    cout << "Welcome to the number guessing game!" << endl;
    cout << "I have generated a random number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    
    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > randomNumber) {
            cout << "Your guess is too high. Try again." << endl;
        } else if (guess < randomNumber) {
            cout << "Your guess is too low. Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number: " << randomNumber << endl;
            break;
        }
    }

    return 0;
}
