#include <iostream>

using Value = int;

template<typename T>
bool ReadArray(T* data, int& size) {
    if (!(std::cin >> size) || size < 0 || size > 100) return false;
    for (int i = 0; i < size; ++i) {
        if (!(std::cin >> data[i]) || data[i] < -1000 || data[i] > 1000) return false;
    }
    return true;
}

template<typename T>
T Sum(const T* data, int size) {
    T result{};
    for (int i = 0; i < size; ++i) result += data[i];
    return result;
}

int main() {
    Value data[100]{};
    int size = 0;
    if (!ReadArray(data, size)) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    std::cout << Sum(data, size) << '\n';
}
