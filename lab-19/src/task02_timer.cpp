#include <algorithm>
#include <iomanip>
#include <iostream>

class Timer {
private:
    int totalSeconds_;

public:
    Timer(int hours, int minutes, int seconds)
        : totalSeconds_(hours * 3600 + minutes * 60 + seconds) {}

    Timer()
        : Timer(0, 1, 0) {}

    Timer(const Timer& other)
        : totalSeconds_(other.totalSeconds_) {}

    void Tick(int elapsed) {
        totalSeconds_ = std::max(0, totalSeconds_ - elapsed);
    }

    void Print() const {
        int hours = totalSeconds_ / 3600;
        int minutes = (totalSeconds_ % 3600) / 60;
        int seconds = totalSeconds_ % 60;

        std::cout << std::setfill('0')
                  << std::setw(2) << hours << ':'
                  << std::setw(2) << minutes << ':'
                  << std::setw(2) << seconds << '\n';
    }
};

int main() {
    int hours, minutes, seconds, elapsed;
    std::cin >> hours >> minutes >> seconds >> elapsed;

    Timer standard;
    Timer original(hours, minutes, seconds);
    Timer copy(original);

    copy.Tick(elapsed);

    standard.Print();
    original.Print();
    copy.Print();
}
