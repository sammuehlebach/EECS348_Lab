#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Account {
protected:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    Account(string number, string holder, double bal) : accountNumber(number), accountHolder(holder), balance(bal) {}

    virtual void displayDetails() {
        cout << "Account ID: " << accountNumber << endl;
        cout << "Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Withdrawal amount exceeds balance" << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    friend ostream& operator<<(ostream& os, Account& acc) {
        acc.displayDetails();
        return os;
    }
};

class SavingsAccount: public Account {
    double interestRate;

public:
    SavingsAccount(string number, string holder, double bal, double rate)
        : Account(number, holder, bal), interestRate(rate) {}

    void displayDetails() override {
        cout << "Account Details for Savings Account (ID: " << accountNumber << "):" << endl;
        cout << "   Holder: " << accountHolder << endl;
        cout << "   Balance: $" << fixed << setprecision(2) << balance << endl;
        cout << "   Interest Rate: " << interestRate * 100 << "%" << endl << endl;
    }

    void withdraw(double amount) override {
        if (balance - amount < 500) {
            cout << "Minimum balance requirement not met" << endl;
        } else {
            Account::withdraw(amount);
        }
    }
};

class CurrentAccount : public Account {
    double overdraftLimit;

public:
    CurrentAccount(string number, string holder, double bal, double limit)
        : Account(number, holder, bal), overdraftLimit(limit) {}

    void displayDetails() override {
        cout << "Account Details for Current Account (ID: " << accountNumber << "):" << endl;
        cout << "   Holder: " << accountHolder << endl;
        cout << "   Balance: $" << fixed << setprecision(2) << balance << endl;
        cout << "   Overdraft Limit: $" << overdraftLimit << endl << endl;
    }

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
        } else {
            cout << "Overdraft Limit exceeded" << endl;
        }
    }

    CurrentAccount& operator+(SavingsAccount& other) {
        double transferAmount = 300; 
        if (other.getBalance() >= transferAmount) {
            this->balance += transferAmount;
            other.withdraw(transferAmount);
        } else {
            cout << "Not enough balance in Savings Account to transfer." << endl;
        }
        return *this;
    }
};

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    savings.deposit(500);
    current.withdraw(1000);
    
    cout << "Account details after deposit and withdrawel:" << endl;

    savings.displayDetails();
    current.displayDetails();

    current = current + savings;

    cout << "Account Details after transfer: " << endl;

    savings.displayDetails();
    current.displayDetails();

    return 0;
}