#include <iostream>
#include <string>

template<typename T, int N = 3>
class Stack {
    static_assert(N > 0);
    T data[N]{};
    int count = 0;
public:
    bool Push(const T& value) {
        if (count == N) return false;
        data[count++] = value;
        return true;
    }
    bool Pop(T& result) {
        if (count == 0) return false;
        result = data[--count];
        return true;
    }
    int Size() const { return count; }
};

int main() {
    int commands{};
    std::string names[100];
    int arguments[100]{};
    if (!(std::cin >> commands) || commands < 0 || commands > 100) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    for (int i = 0; i < commands; ++i) {
        if (!(std::cin >> names[i]) ||
            (names[i] != "push" && names[i] != "pop" && names[i] != "size") ||
            (names[i] == "push" && !(std::cin >> arguments[i]))) {
            std::cout << "Некоректні дані\n";
            return 0;
        }
    }
    Stack<int> container;
    for (int i = 0; i < commands; ++i) {
        if (names[i] == "push") {
            std::cout << (container.Push(arguments[i]) ? "OK" : "Помилка") << '\n';
        } else if (names[i] == "pop") {
            int result{};
            if (container.Pop(result)) std::cout << result << '\n';
            else std::cout << "Помилка\n";
        } else {
            std::cout << container.Size() << '\n';
        }
    }
}
