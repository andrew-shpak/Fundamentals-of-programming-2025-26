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
    std::string normalized;
    for (char c : text) {
        if (c >= 'A' && c <= 'Z') c = static_cast<char>(c - 'A' + 'a');
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) normalized += c;
    }
    bool palindrome = true;
    for (std::size_t i = 0; i < normalized.size() / 2; ++i) {
        if (normalized[i] != normalized[normalized.size() - 1 - i]) {
            palindrome = false;
            break;
        }
    }
    std::cout << (palindrome ? "Так" : "Ні") << '\n';
}
