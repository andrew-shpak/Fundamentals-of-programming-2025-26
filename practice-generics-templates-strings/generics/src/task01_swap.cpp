#include <iostream>

using Value = int;

template<typename T>
void Swap(T& a, T& b) {
    T temporary = a;
    a = b;
    b = temporary;
}

int main() {
    Value a{}, b{};
    if (!(std::cin >> a >> b) || a < -1000 || a > 1000 || b < -1000 || b > 1000) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    Swap(a, b);
    std::cout << a << ' ' << b << '\n';
}
