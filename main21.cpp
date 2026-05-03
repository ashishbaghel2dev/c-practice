#include <iostream>
#include <stdexcept>
using namespace std;

// ================= TEMPLATE CLASS =================
template <typename T>
class Order {
private:
    T orderAmount;

public:
    Order(T amount) {
        orderAmount = amount;
    }

    // Validate and place order
    void placeOrder() {
        if (orderAmount < 0) {
            throw invalid_argument("Order amount cannot be negative!");
        }
        cout << "Order placed successfully!" << endl;
    }

    // Process payment
    T makePayment(T walletBalance) {
        if (walletBalance < orderAmount) {
            throw runtime_error("Insufficient wallet balance!");
        }

        walletBalance -= orderAmount;
        cout << "Payment successful!" << endl;
        return walletBalance;
    }
};

// ================= MAIN FUNCTION =================
int main() {
    try {
        double wallet, amount;

        cout << "Enter wallet balance: ";
        cin >> wallet;

        cout << "Enter order amount: ";
        cin >> amount;

        // Template used with double
        Order<double> obj(amount);

        obj.placeOrder();

        double remaining = obj.makePayment(wallet);

        cout << "Remaining Wallet Balance: " << remaining << endl;
    }
    catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}