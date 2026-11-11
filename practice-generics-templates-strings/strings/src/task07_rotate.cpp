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
    long long shift{};
    if (!(std::cin >> shift) || shift < 0 || shift > 1000000000) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    std::string result;
    if (!text.empty()) {
        std::size_t offset = static_cast<std::size_t>(shift) % text.size();
        std::size_t split = text.size() - offset;
        for (std::size_t i = split; i < text.size(); ++i) result += text[i];
        for (std::size_t i = 0; i < split; ++i) result += text[i];
    }
    std::cout << (result.empty() ? "Порожній рядок" : result) << '\n';
}
