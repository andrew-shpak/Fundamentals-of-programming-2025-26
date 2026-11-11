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
    for (char c : text) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
            std::cout << "Некоректні дані\n";
            return 0;
        }
    }
    std::string result;
    std::size_t i = 0;
    while (i < text.size()) {
        std::size_t end = i + 1;
        while (end < text.size() && text[end] == text[i]) ++end;
        result += text[i];
        result += std::to_string(end - i);
        i = end;
    }
    std::cout << (result.empty() ? "Порожній рядок" : result) << '\n';
}
