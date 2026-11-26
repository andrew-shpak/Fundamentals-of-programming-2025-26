#include <algorithm>
#include <iostream>

class Result {
private:
    int score_;

public:
    explicit Result(int score)
        : score_(score) {}

    Result(const Result& other)
        : score_(other.score_) {
        std::cout << "COPY " << score_ << '\n';
    }

    void Add(int bonus) {
        score_ = std::min(100, score_ + bonus);
    }

    int Score() const {
        return score_;
    }
};

void Improve(Result result, int bonus) {
    result.Add(bonus);
    std::cout << "LOCAL " << result.Score() << '\n';
}

void Show(const Result& result) {
    std::cout << "ORIGINAL " << result.Score() << '\n';
}

int main() {
    int score, bonus;
    std::cin >> score >> bonus;

    const Result original(score);

    Improve(original, bonus);
    Show(original);
}
