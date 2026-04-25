#include <iostream>
using namespace std;

// Base Class
class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    // Encapsulation (getter)
    double getBalance() {
        return balance;
    }

    // Deposit
    void deposit(double amount) {
        balance += amount;
        cout << "Amount deposited successfully.\n";
    }

    // Withdraw
    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful.\n";
        } else {
            cout << "Insufficient balance.\n";
        }
    }

    // Polymorphism
    virtual void calculateInterest() {
        cout << "No interest for base account.\n";
    }

    virtual void displayAccountInfo() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nAccount Holder: " << accountHolderName;
        cout << "\nBalance: " << balance << endl;
    }

    virtual ~BankAccount() {}
};

// Savings Account
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal) {
        interestRate = rate;
    }

    void calculateInterest() override {
        double interest = balance * interestRate / 100;
        cout << "Savings Interest: " << interest << endl;
    }
};

// Checking Account
class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal) {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrawal successful (Overdraft allowed).\n";
        } else {
            cout << "Overdraft limit exceeded.\n";
        }
    }
};

// Fixed Deposit Account
class FixedDepositAccount : public BankAccount {
private:
    int term;

public:
    FixedDepositAccount(int accNo, string name, double bal, int t)
        : BankAccount(accNo, name, bal) {
        term = t;
    }

    void calculateInterest() override {
        double rate = 7.0; // fixed rate
        double interest = balance * rate * term / 100;
        cout << "Fixed Deposit Interest: " << interest << endl;
    }
};

// Main Function
int main() {
    BankAccount* account = nullptr;
    int choice;

    do {
        cout << "\n===== Banking System Menu =====\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Create Fixed Deposit Account\n";
        cout << "4. Deposit\n";
        cout << "5. Withdraw\n";
        cout << "6. Display Info\n";
        cout << "7. Calculate Interest\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int accNo;
        string name;
        double balance, amount;

        switch (choice) {
        case 1:
            cout << "Enter Account Number, Name, Balance, Interest Rate: ";
            cin >> accNo >> name >> balance;
            double rate;
            cin >> rate;
            account = new SavingsAccount(accNo, name, balance, rate);
            break;

        case 2:
            cout << "Enter Account Number, Name, Balance, Overdraft Limit: ";
            cin >> accNo >> name >> balance;
            double limit;
            cin >> limit;
            account = new CheckingAccount(accNo, name, balance, limit);
            break;

        case 3:
            cout << "Enter Account Number, Name, Balance, Term (months): ";
            cin >> accNo >> name >> balance;
            int term;
            cin >> term;
            account = new FixedDepositAccount(accNo, name, balance, term);
            break;

        case 4:
            if (account) {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account->deposit(amount);
            } else {
                cout << "Create account first!\n";
            }
            break;

        case 5:
            if (account) {
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account->withdraw(amount);
            } else {
                cout << "Create account first!\n";
            }
            break;

        case 6:
            if (account)
                account->displayAccountInfo();
            else
                cout << "Create account first!\n";
            break;

        case 7:
            if (account)
                account->calculateInterest();
            else
                cout << "Create account first!\n";
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    delete account;
    return 0;
}