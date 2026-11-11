#include <iostream>
#include <stdexcept>

template<typename T, int N>
class FixedArray {
    static_assert(N > 0);
    T data[N]{};
public:
    T& At(int index) {
        if (index < 0 || index >= N) throw std::out_of_range("index");
        return data[index];
    }
    const T& At(int index) const {
        if (index < 0 || index >= N) throw std::out_of_range("index");
        return data[index];
    }
};

int main() {
    FixedArray<int, 5> values;
    for (int i = 0; i < 5; ++i) {
        if (!(std::cin >> values.At(i))) {
            std::cout << "Некоректні дані\n";
            return 0;
        }
    }
    int index{}, replacement{};
    if (!(std::cin >> index >> replacement)) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    try {
        values.At(index) = replacement;
        const auto& view = values;
        for (int i = 0; i < 5; ++i) {
            if (i != 0) std::cout << ' ';
            std::cout << view.At(i);
        }
        std::cout << '\n';
    } catch (const std::out_of_range&) {
        std::cout << "Некоректні дані\n";
    }
}
