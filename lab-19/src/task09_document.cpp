#include <iostream>
#include <string>

class Document {
private:
    inline static int activeCount_ = 0;

    std::string name_;

public:
    explicit Document(const std::string& name)
        : name_(name) {
        ++activeCount_;
    }

    Document(const Document& other)
        : name_(other.name_) {
        ++activeCount_;
    }

    ~Document() {
        --activeCount_;
    }

    static int ActiveCount() {
        return activeCount_;
    }

    const std::string& Name() const {
        return name_;
    }
};

int main() {
    std::string name;
    std::cin >> name;

    std::cout << Document::ActiveCount() << '\n';

    {
        Document original(name);
        std::cout << Document::ActiveCount() << '\n';

        {
            Document firstCopy(original);
            std::cout << Document::ActiveCount() << '\n';

            {
                Document secondCopy(firstCopy);

                std::cout << Document::ActiveCount() << ' '
                          << secondCopy.Name() << '\n';
            }

            std::cout << Document::ActiveCount() << '\n';
        }

        std::cout << Document::ActiveCount() << '\n';
    }

    std::cout << Document::ActiveCount() << '\n';
}
