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
    int last[128];
    for (int& position : last) position = -1;
    int left = 0, best_start = 0, best_length = 0;
    for (int right = 0; right < static_cast<int>(text.size()); ++right) {
        unsigned char c = static_cast<unsigned char>(text[right]);
        if (last[c] >= left) left = last[c] + 1;
        last[c] = right;
        int length = right - left + 1;
        if (length > best_length) {
            best_start = left;
            best_length = length;
        }
    }
    std::cout << "Довжина: " << best_length << '\n';
    if (best_length == 0) std::cout << "Межі: -1 -1\nПорожній рядок\n";
    else {
        std::cout << "Межі: " << best_start << ' ' << best_start + best_length - 1 << '\n';
        for (int i = best_start; i < best_start + best_length; ++i) std::cout << text[i];
        std::cout << '\n';
    }
}
