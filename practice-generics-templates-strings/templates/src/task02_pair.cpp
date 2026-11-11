#include <iostream>
#include <string>

template<typename First, typename Second>
struct Pair {
    First first;
    Second second;
};

int main() {
    Pair<std::string, int> result;
    if (!(std::cin >> result.first >> result.second)) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    std::cout << result.first << ": " << result.second << '\n';
}
