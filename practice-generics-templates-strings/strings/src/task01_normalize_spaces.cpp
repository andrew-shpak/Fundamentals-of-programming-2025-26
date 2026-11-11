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
    std::string result;
    bool pending_space = false;
    for (char c : text) {
        if (c == ' ') pending_space = !result.empty();
        else {
            if (pending_space) result += ' ';
            result += c;
            pending_space = false;
        }
    }
    std::cout << (result.empty() ? "Порожній рядок" : result) << '\n';
}
