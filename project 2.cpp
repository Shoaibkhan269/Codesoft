#include <iostream>
using namespace std;
void displayMenu() {
    cout << "Select operation:\n";
    cout << "1. Addition \n";
    cout << "2. Subtraction \n";
    cout << "3. Multiplication \n";
    cout << "4. Division \n";
    cout << "5. Exit\n";
    cout << "Enter choice (1-5): ";
}
int main() {
    int choice;
    double n1, n2, result;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting the calculator.\n";
            break;
        }
        if (choice < 1 || choice > 5) {
            cout << "Invalid choice! Please select a valid operation.\n";
            continue;
        }

        cout << "Enter first number: ";
        cin >> n1;
        cout << "Enter second number: ";
        cin >> n2;
        switch (choice) {
            case 1:
                result = n1 + n2;
                cout << "Result: " << n1 << " + " << n2 << " = " << result << endl;
                break;
            case 2:
                result = n1 - n2;
                cout << "Result: " << n1 << " - " << n2 << " = " << result << endl;
                break;
            case 3:
                result = n1 * n2;
                cout << "Result: " << n1 << " * " << n2 << " = " << result << endl;
                break;
            case 4:
                if (n2 != 0) {
                    result = n1 / n2;
                    cout << "Result: " << n1 << " / " << n2 << " = " << result << endl;
                } else {
                    cout << "Error: Division by zero is not allowed.\n";
                }
                break;
        }
        cout << endl;
    }
    return 0;
}
