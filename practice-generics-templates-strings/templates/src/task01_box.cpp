#include <iostream>

template<typename T>
class Box {
    T value;
public:
    explicit Box(const T& initial) : value(initial) {}
    const T& Get() const { return value; }
    void Set(const T& replacement) { value = replacement; }
};

int main() {
    int initial{}, replacement{};
    if (!(std::cin >> initial >> replacement)) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    Box<int> box(initial);
    std::cout << box.Get() << '\n';
    box.Set(replacement);
    std::cout << box.Get() << '\n';
}
