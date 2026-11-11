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
    int frequencies[128]{};
    bool printed[128]{};
    for (unsigned char c : text) ++frequencies[c];
    if (text.empty()) std::cout << "Порожній рядок\n";
    for (unsigned char c : text) {
        if (!printed[c]) {
            std::cout << '[' << static_cast<char>(c) << "]: " << frequencies[c] << '\n';
            printed[c] = true;
        }
    }
}
