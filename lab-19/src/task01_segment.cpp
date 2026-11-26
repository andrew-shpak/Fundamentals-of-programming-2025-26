#include <algorithm>
#include <iostream>

class Segment {
private:
    int start_;
    int end_;

public:
    Segment(int a, int b)
        : start_(std::min(a, b)),
          end_(std::max(a, b)) {}

    Segment(const Segment& other)
        : start_(other.start_),
          end_(other.end_) {}

    void Shift(int delta) {
        start_ += delta;
        end_ += delta;
    }

    int Length() const {
        return end_ - start_;
    }

    void Print() const {
        std::cout << start_ << ' '
                  << end_ << ' '
                  << Length() << '\n';
    }
};

int main() {
    int a, b, delta;
    std::cin >> a >> b >> delta;

    Segment original(a, b);
    Segment copy(original);

    copy.Shift(delta);

    original.Print();
    copy.Print();
}
