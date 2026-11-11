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
void PrintArray(const T* data, int size) {
    if (size == 0) std::cout << "Порожній масив";
    for (int i = 0; i < size; ++i) {
        if (i != 0) std::cout << ' ';
        std::cout << data[i];
    }
    std::cout << '\n';
}

template<typename T>
int Unique(const T* data, int size, T* result) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        bool seen = false;
        for (int j = 0; j < count; ++j) {
            if (result[j] == data[i]) {
                seen = true;
                break;
            }
        }
        if (!seen) result[count++] = data[i];
    }
    return count;
}

int main() {
    Value data[100]{};
    int size = 0;
    if (!ReadArray(data, size)) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    Value result[100]{};
    int count = Unique(data, size, result);
    PrintArray(result, count);
}
