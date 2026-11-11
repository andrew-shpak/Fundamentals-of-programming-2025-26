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
int FindFirst(const T* data, int size, const T& target) {
    for (int i = 0; i < size; ++i) {
        if (data[i] == target) return i;
    }
    return -1;
}

int main() {
    Value data[100]{};
    int size = 0;
    if (!ReadArray(data, size)) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    Value target{};
    if (!(std::cin >> target) || target < -1000 || target > 1000) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    std::cout << FindFirst(data, size, target) << '\n';
}
