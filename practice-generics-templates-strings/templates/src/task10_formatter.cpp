#include <iostream>

template<typename T>
struct Formatter {
    static void Print(const T& value) { std::cout << value << '\n'; }
};

template<>
struct Formatter<bool> {
    static void Print(const bool& value) {
        std::cout << (value ? "Так" : "Ні") << '\n';
    }
};

int main() {
    int number{}, flag{};
    if (!(std::cin >> number >> flag) || (flag != 0 && flag != 1)) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    Formatter<int>::Print(number);
    Formatter<bool>::Print(flag == 1);
}
