#include <iostream>

using namespace std;

class DivisionCalculator {
private:
    float num1;
    float num2;

public:
    void getInput() {
        // Accepting the first float number
        cout << "Enter the first float number: ";
        while (!(cin >> num1)) {
            cin.clear();  // Clearing the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discarding invalid input
            cout << "Invalid input. Please enter a float number: ";
        }

        // Accepting the second float number
        cout << "Enter the second float number: ";
        while (!(cin >> num2)) {
            cin.clear();  // Clearing the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discarding invalid input
            cout << "Invalid input. Please enter a float number: ";
        }
    }

    void calculateDivision() {
        // Checking for division by zero
        if (num2 == 0) {
            // Handling division by zero without using stdexcept
            cerr << "Error: Division by zero is not allowed." << endl;
            return;
        }

        // Performing the division
        float result = num1 / num2;

        // Displaying the result
        cout << "Result of division: " << result << endl;
    }
};

int main() {
    DivisionCalculator calculator;

    // Get input and calculate division
    calculator.getInput();
    calculator.calculateDivision();

    return 0;
}

