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
    std::string replacement;
    if (!std::getline(std::cin, replacement) || replacement.size() > 1000) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    for (unsigned char c : replacement) {
        if (c < 32 || c > 126) {
            std::cout << "Некоректні дані\n";
            return 0;
        }
    }
    std::string result;
    std::size_t i = 0;
    while (i < text.size()) {
        bool match = i + pattern.size() <= text.size();
        for (std::size_t j = 0; match && j < pattern.size(); ++j) {
            if (text[i + j] != pattern[j]) match = false;
        }
        if (match) {
            result += replacement;
            i += pattern.size();
        } else result += text[i++];
    }
    std::cout << (result.empty() ? "Порожній рядок" : result) << '\n';
}
