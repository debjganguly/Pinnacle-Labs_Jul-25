#include <iostream>
using namespace std;

// Starting our Project
int main() {

    // Initisializing Variables
    int pin=1234,enterpin,balance = 10e5;
    int input, amount;

    // Greetings and enter
    cout << "----------------------------------------" << endl;
    cout << "Greetings! Welcome to Fool Yourslf Bank!" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Please enter your 4-Digit PIN: ";
    cin >> enterpin;

    // Logic Flow 
    if(enterpin==pin) {
        cout << " \nAccess Granted.Welcome to your account !!!" << endl;

        

        // Logic Control as per user input
        while(input!=4) {
            cout << "------------------------------------" << endl;
                // Showing Main Menu
                cout << "1. Check Balance" << endl;
                cout << "2. Deposit" << endl;
                cout << "3. Withdraw" << endl;
                cout << "4. Exit" << endl;
                cout << "------------------------------------" << endl;
                cin >> input;
                switch(input) {
                case 1:
                cout << "Your Balance: " << balance << endl;
                break;

                case 2:
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                if (amount > 0) {
                        balance += amount;
                        cout << "Deposited rupees" << amount << " successfully." << endl;
                    } else {
                        cout << "Invalid deposit amount." << endl;
                    }
                break;

                case 3:
                cout << "Enter Withdrawal Amount: ";
                cin >> amount;
                if (amount > 0 && amount <= balance) {
                        balance -= amount;
                        cout << "Withdrawal of rupees " << amount << " successful." << endl;
                    } else {
                        cout << "Insufficient balance or invalid amount!" << endl;
                    }
                break;

                case 4:
                cout << "Thank you for banking with us. Goodbye!" << endl;
                return 0;

                default: cout << "Looks like you want to perform some out of books task with your money\n Please select one from the list given";
                break;

            }
        }
    } else {
        cout << "Entered Pin does not match with your registered pin !!!" << endl;
    }

}