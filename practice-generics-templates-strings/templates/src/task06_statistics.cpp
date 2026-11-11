#include <iostream>

template<typename T>
class Statistics {
    int count = 0;
    T total{}, minimum{}, maximum{};
public:
    void Add(const T& value) {
        if (count == 0) minimum = maximum = value;
        else {
            if (value < minimum) minimum = value;
            if (maximum < value) maximum = value;
        }
        total += value;
        ++count;
    }
    int Count() const { return count; }
    T Sum() const { return total; }
    bool MinMax(T& low, T& high) const {
        if (count == 0) return false;
        low = minimum;
        high = maximum;
        return true;
    }
};

int main() {
    int size{};
    Statistics<int> stats;
    if (!(std::cin >> size) || size < 0 || size > 100) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    for (int i = 0; i < size; ++i) {
        int value{};
        if (!(std::cin >> value) || value < -1000 || value > 1000) {
            std::cout << "Некоректні дані\n";
            return 0;
        }
        stats.Add(value);
    }
    std::cout << "Кількість: " << stats.Count() << "\nСума: " << stats.Sum() << '\n';
    int low{}, high{};
    if (stats.MinMax(low, high)) std::cout << low << ' ' << high << '\n';
    else std::cout << "Немає значень\n";
}
