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
void InsertionSort(T* data, int size) {
    for (int i = 1; i < size; ++i) {
        T current = data[i];
        int position = i;
        while (position > 0 && current < data[position - 1]) {
            data[position] = data[position - 1];
            --position;
        }
        data[position] = current;
    }
}

int main() {
    Value data[100]{};
    int size = 0;
    if (!ReadArray(data, size)) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    InsertionSort(data, size);
    PrintArray(data, size);
}
