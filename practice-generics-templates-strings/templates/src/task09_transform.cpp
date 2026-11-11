#include <iostream>

template<typename T, typename Operation>
struct Transformer {
    static void Apply(T* data, int size, const Operation& operation) {
        for (int i = 0; i < size; ++i) data[i] = operation(data[i]);
    }
};

struct Square {
    int operator()(int value) const { return value * value; }
};

int main() {
    int size{}, data[100]{};
    if (!(std::cin >> size) || size < 0 || size > 100) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    for (int i = 0; i < size; ++i) {
        if (!(std::cin >> data[i]) || data[i] < -1000 || data[i] > 1000) {
            std::cout << "Некоректні дані\n";
            return 0;
        }
    }
    Transformer<int, Square>::Apply(data, size, Square{});
    if (size == 0) std::cout << "Порожній масив";
    for (int i = 0; i < size; ++i) {
        if (i != 0) std::cout << ' ';
        std::cout << data[i];
    }
    std::cout << '\n';
}
