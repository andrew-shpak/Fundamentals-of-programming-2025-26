#include <iostream>
#include <string>

int main() {
    std::string text;
    if (!std::getline(std::cin, text) || text.size() > 1000) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    for (unsigned char c : text) {
        if (c < 32 || c > 126) {
            std::cout << "Некоректні дані\n";
            return 0;
        }
    }
    std::string pattern;
    if (!std::getline(std::cin, pattern) || pattern.size() > 1000) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    for (unsigned char c : pattern) {
        if (c < 32 || c > 126) {
            std::cout << "Некоректні дані\n";
            return 0;
        }
    }
    if (pattern.empty()) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    bool found = false;
    for (std::size_t i = 0; i + pattern.size() <= text.size(); ++i) {
        bool match = true;
        for (std::size_t j = 0; j < pattern.size(); ++j) {
            if (text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            if (found) std::cout << ' ';
            std::cout << i;
            found = true;
        }
    }
    if (!found) std::cout << -1;
    std::cout << '\n';
}
