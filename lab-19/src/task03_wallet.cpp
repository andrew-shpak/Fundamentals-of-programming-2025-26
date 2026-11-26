#include <iostream>

class Wallet {
private:
    int balance_;

public:
    explicit Wallet(int balance)
        : balance_(balance) {}

    Wallet(const Wallet& other)
        : balance_(other.balance_) {}

    bool Spend(int amount) {
        if (amount > balance_) {
            return false;
        }

        balance_ -= amount;
        return true;
    }

    int Balance() const {
        return balance_;
    }
};

int main() {
    int initialBalance, n;
    std::cin >> initialBalance >> n;

    Wallet original(initialBalance);
    Wallet copy(original);

    for (int i = 0; i < n; ++i) {
        int amount;
        std::cin >> amount;

        if (copy.Spend(amount)) {
            std::cout << "OK\n";
        } else {
            std::cout << "REJECTED\n";
        }
    }

    std::cout << original.Balance() << ' '
              << copy.Balance() << '\n';
}
