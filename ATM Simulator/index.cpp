#include <iostream>
using namespace std;

int main() {
    // Initializing Variables
    const int correctPin = 1234;
    int enterpin, balance = 10e5; // ₹1,000,000
    int input = 0, amount;
    int attempts = 0;
    const int maxAttempts = 3;

    // Greetings
    cout << "----------------------------------------" << endl;
    cout << "Greetings! Welcome to Fool Yourself Bank!" << endl;
    cout << "----------------------------------------" << endl;

    // PIN Check with 3 Attempts
    while (attempts < maxAttempts) {
        cout << "Please enter your 4-Digit PIN: ";
        cin >> enterpin;

        if (enterpin == correctPin) {
            cout << "\nAccess Granted. Welcome to your account!" << endl;

            // Main Menu Loop
            while (input != 4) {
                cout << "\n------------------------------------" << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Deposit" << endl;
                cout << "3. Withdraw" << endl;
                cout << "4. Exit" << endl;
                cout << "------------------------------------" << endl;
                cout << "Choose an option: ";
                cin >> input;

                switch (input) {
                    case 1:
                        cout << "Your Balance: ₹" << balance << endl;
                        break;

                    case 2:
                        cout << "Enter Deposit Amount: ₹";
                        cin >> amount;
                        if (amount > 0) {
                            balance += amount;
                            cout << "Deposited ₹" << amount << " successfully." << endl;
                        } else {
                            cout << "Invalid deposit amount." << endl;
                        }
                        break;

                    case 3:
                        cout << "Enter Withdrawal Amount: ₹";
                        cin >> amount;
                        if (amount > 0 && amount <= balance) {
                            balance -= amount;
                            cout << "Withdrawal of ₹" << amount << " successful." << endl;
                        } else {
                            cout << "Insufficient balance or invalid amount!" << endl;
                        }
                        break;

                    case 4:
                        cout << "\nThank you for banking with us. Goodbye!" << endl;
                        break;

                    default:
                        cout << "Invalid option. Please select from the menu." << endl;
                }
            }

            return 0; // Exit after successful session
        } else {
            attempts++;
            cout << "Incorrect PIN. Attempts left: " << (maxAttempts - attempts) << endl;

            if (attempts == maxAttempts) {
                cout << "\nMaximum attempts reached. Your account has been locked!" << endl;
                cout << "Please contact customer support.\n";
                return 0;
            }
        }
    }

    return 0;
}
