#include <iostream>
#include <string>

class Record {
private:
    std::string label_;

public:
    explicit Record(const std::string& label)
        : label_(label) {
        std::cout << "NEW " << label_ << '\n';
    }

    Record()
        : Record("empty") {}

    Record(const Record& other)
        : label_(other.label_) {
        std::cout << "COPY " << label_ << '\n';
    }

    ~Record() {
        std::cout << "DELETE " << label_ << '\n';
    }

    void Rename(const std::string& label) {
        label_ = label;
    }
};

int main() {
    std::string firstLabel, secondLabel, newLabel;
    std::cin >> firstLabel >> secondLabel >> newLabel;

    {
        Record records[3] = {
            Record(firstLabel),
            Record(secondLabel),
            Record()
        };

        {
            Record copy(records[0]);
            copy.Rename(newLabel);

            std::cout << "INNER\n";
        }

        std::cout << "ARRAY\n";
    }

    std::cout << "END\n";
}
