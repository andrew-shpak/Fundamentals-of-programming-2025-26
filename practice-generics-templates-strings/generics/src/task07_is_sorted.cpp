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
bool IsSorted(const T* data, int size) {
    for (int i = 1; i < size; ++i) {
        if (data[i] < data[i - 1]) return false;
    }
    return true;
}

int main() {
    Value data[100]{};
    int size = 0;
    if (!ReadArray(data, size)) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    std::cout << (IsSorted(data, size) ? "Так" : "Ні") << '\n';
}
