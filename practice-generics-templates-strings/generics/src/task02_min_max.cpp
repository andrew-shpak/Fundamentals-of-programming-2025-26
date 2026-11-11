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
void FindMinMax(const T* data, int size, T& minimum, T& maximum) {
    minimum = data[0];
    maximum = data[0];
    for (int i = 1; i < size; ++i) {
        if (data[i] < minimum) minimum = data[i];
        if (maximum < data[i]) maximum = data[i];
    }
}

int main() {
    Value data[100]{};
    int size = 0;
    if (!ReadArray(data, size)) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    if (size == 0) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    Value minimum{}, maximum{};
    FindMinMax(data, size, minimum, maximum);
    std::cout << minimum << ' ' << maximum << '\n';
}
