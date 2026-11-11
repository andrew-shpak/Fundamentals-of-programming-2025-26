#include <iostream>
#include <string>

int main() {
    std::string first;
    if (!std::getline(std::cin, first) || first.size() > 1000) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    for (unsigned char c : first) {
        if (c < 32 || c > 126) {
            std::cout << "Некоректні дані\n";
            return 0;
        }
    }
    std::string second;
    if (!std::getline(std::cin, second) || second.size() > 1000) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    for (unsigned char c : second) {
        if (c < 32 || c > 126) {
            std::cout << "Некоректні дані\n";
            return 0;
        }
    }
    int differences[128]{};
    for (char c : first) {
        if (c == ' ') continue;
        if (c >= 'A' && c <= 'Z') c = static_cast<char>(c - 'A' + 'a');
        ++differences[static_cast<unsigned char>(c)];
    }
    for (char c : second) {
        if (c == ' ') continue;
        if (c >= 'A' && c <= 'Z') c = static_cast<char>(c - 'A' + 'a');
        --differences[static_cast<unsigned char>(c)];
    }
    bool equal = true;
    for (int difference : differences) {
        if (difference != 0) equal = false;
    }
    std::cout << (equal ? "Так" : "Ні") << '\n';
}
