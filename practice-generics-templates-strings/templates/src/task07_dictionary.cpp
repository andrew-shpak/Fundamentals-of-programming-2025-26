#include <iostream>
#include <string>

template<typename Key, typename Value, int N>
class Dictionary {
    static_assert(N > 0);
    Key keys[N]{};
    Value values[N]{};
    int count = 0;
public:
    bool Set(const Key& key, const Value& value) {
        for (int i = 0; i < count; ++i) {
            if (keys[i] == key) {
                values[i] = value;
                return true;
            }
        }
        if (count == N) return false;
        keys[count] = key;
        values[count++] = value;
        return true;
    }
    bool TryGet(const Key& key, Value& result) const {
        for (int i = 0; i < count; ++i) {
            if (keys[i] == key) {
                result = values[i];
                return true;
            }
        }
        return false;
    }
};

int main() {
    int size{}, values[100]{};
    std::string keys[100], query;
    if (!(std::cin >> size) || size < 0 || size > 100) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    for (int i = 0; i < size; ++i) {
        if (!(std::cin >> keys[i] >> values[i])) {
            std::cout << "Некоректні дані\n";
            return 0;
        }
    }
    if (!(std::cin >> query)) {
        std::cout << "Некоректні дані\n";
        return 0;
    }
    Dictionary<std::string, int, 3> dictionary;
    for (int i = 0; i < size; ++i) {
        std::cout << (dictionary.Set(keys[i], values[i]) ? "OK" : "Помилка") << '\n';
    }
    int result{};
    if (dictionary.TryGet(query, result)) std::cout << result << '\n';
    else std::cout << "Не знайдено\n";
}
