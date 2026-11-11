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
    std::size_t best_start = 0, best_length = 0, i = 0;
    while (i < text.size()) {
        while (i < text.size() && text[i] == ' ') ++i;
        std::size_t start = i;
        while (i < text.size() && text[i] != ' ') ++i;
        if (i - start > best_length) {
            best_start = start;
            best_length = i - start;
        }
    }
    if (best_length == 0) std::cout << "Немає слів\n";
    else {
        std::cout << "Слово: ";
        for (std::size_t j = best_start; j < best_start + best_length; ++j) std::cout << text[j];
        std::cout << "\nДовжина: " << best_length << '\n';
    }
}
