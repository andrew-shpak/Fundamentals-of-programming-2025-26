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
bool IsSorted(const T* data, int size) {
    for (int i = 1; i < size; ++i) {
        if (data[i] < data[i - 1]) return false;
    }
    return true;
}

template<typename T>
int MergeSorted(const T* first, int n, const T* second, int m, T* result) {
    int i = 0, j = 0, count = 0;
    while (i < n && j < m) {
        if (second[j] < first[i]) result[count++] = second[j++];
        else result[count++] = first[i++];
    }
    while (i < n) result[count++] = first[i++];
    while (j < m) result[count++] = second[j++];
    return count;
}

int main() {
    Value first[100]{}, second[100]{}, result[200]{};
    int n = 0, m = 0;
    if (!ReadArray(first, n) || !ReadArray(second, m) ||
        !IsSorted(first, n) || !IsSorted(second, m)) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    int count = MergeSorted(first, n, second, m, result);
    PrintArray(result, count);
}
