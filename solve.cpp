// Apply object-oriented concepts in C++ to design a banking system that manages different account types:
// Savings, Checking, and Business. Each account calculates interest differently (4% for Savings, 2% for Checking, and 5% for Business),
//  with additional features such as a 1% bonus for Savings over Rs. 10,000, a Rs. 5 fee for Checking, and 2% extra interest for Business accounts over Rs. 50,000.
//   Create an abstract base class BankAccount with a method to calculate interest, ensuring that each derived class implements this method according to its specific rules.
//    Additionally, overload the + operator to add the balances of two accounts. In main), create objects of each account type (Savings, Checking, and Business) using the concept of upcasting,
//    calculate and display their interest, demonstrate operator overloading by adding the balances of two accounts, and display the results. |CO2 (Applying), 7 Marks]

#include <iostream>
using namespace std;


// Abstract base class
class BankAccount {
protected:
    double balance;
public:
    BankAccount(double bal) : balance(bal) {}
    virtual double calculateInterest() = 0; // Pure virtual function    
    double getBalance() const { return balance; }
    // Overload + operator to add balances of two accounts
    BankAccount operator+(const BankAccount& other) {
        return BankAccount(this->balance + other.balance);
    }
};  

// Derived class for Savings Account
class SavingsAccount : public BankAccount {
public:
    SavingsAccount(double bal) : BankAccount(bal) {}
    double calculateInterest() override {
        double interest = balance * 0.04; // 4% interest
        if (balance > 10000) {
            interest += balance * 0.01; // 1% bonus for balances over Rs. 10,000
        }   
        return interest;
    }
};

// Derived class for Checking Account
class CheckingAccount : public BankAccount {
public:    CheckingAccount(double bal) : BankAccount(bal) {}
    double calculateInterest() override {
        return balance * 0.02 - 5; // 2% interest with a Rs. 5 fee
    }
};

// Derived class for Business Account
class BusinessAccount : public BankAccount {
public:
    BusinessAccount(double bal) : BankAccount(bal) {}
    double calculateInterest() override {
        double interest = balance * 0.05; // 5% interest
        if (balance > 50000) {
            interest += balance * 0.02; // 2% extra interest for balances over Rs. 50,000
        }
        return interest;
    }
};

int main() {
    // Create objects of each account type using upcasting
    BankAccount* savings = new SavingsAccount(15000);
    BankAccount* checking = new CheckingAccount(8000);
    BankAccount* business = new BusinessAccount(60000);

    // Calculate and display interest for each account
    cout << "Savings Account Interest: " << savings->calculateInterest() << endl;
    cout << "Checking Account Interest: " << checking->calculateInterest() << endl;
    cout << "Business Account Interest: " << business->calculateInterest() << endl;

    // Demonstrate operator overloading by adding the balances of two accounts
    BankAccount totalBalance = *savings + *checking; // Adding savings and checking accounts
    cout << "Total Balance of Savings and Checking Accounts: " << totalBalance.getBalance() << endl;

    // Clean up
    delete savings;
    delete checking;
    delete business;

    return 0;
}   