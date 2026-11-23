#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Base custom exception class
class BankException : public exception {
protected:
    string message;

public:
    BankException(string msg) {
        message = msg;
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Derived exception class
class InsufficientFundsException : public BankException {
public:
    InsufficientFundsException()
        : BankException("Error: Insufficient balance for withdrawal.") {
    }
};

// Another derived exception class
class InvalidAmountException : public BankException {
public:
    InvalidAmountException()
        : BankException("Error: Amount must be greater than zero.") {
    }
};

class BankAccount {
private:
    string name;
    double balance;

public:
    BankAccount(string n, double b) {
        name = n;
        balance = b;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw InvalidAmountException();
        }
        balance += amount;
    }

    void withdraw(double amount) {
        // Validate first before modifying the balance
        if (amount <= 0) {
            throw InvalidAmountException();
        }
        if (amount > balance) {
            throw InsufficientFundsException();
        }

        // State changes only after all checks succeed
        balance -= amount;
    }

    void display() {
        cout << "Account Holder: " << name << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main() {
    string accountName;
    double initialBalance, depositAmount, withdrawalAmount1, withdrawalAmount2;

    cout << "Enter account holder name: ";
    getline(cin >> ws, accountName);
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(accountName, initialBalance);
    cout << "Initial Account Details:" << endl;
    account.display();

    try {
        cout << "\nEnter deposit amount: ";
        cin >> depositAmount;
        account.deposit(depositAmount);
        cout << "Enter first withdrawal amount: ";
        cin >> withdrawalAmount1;
        account.withdraw(withdrawalAmount1);
        cout << "Enter second withdrawal amount: ";
        cin >> withdrawalAmount2;
        account.withdraw(withdrawalAmount2);
    } catch (const InsufficientFundsException& e) {
        cout << e.what() << endl;
    } catch (const InvalidAmountException& e) {
        cout << e.what() << endl;
    } catch (const BankException& e) {
        cout << "Bank Exception: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "General Exception: " << e.what() << endl;
    }

    cout << "\nFinal Account Details:" << endl;
    account.display();

    return 0;
}