#include <iomanip>
#include <iostream>

class GradeBook {
private:
    int grades_[10];
    int count_;

public:
    GradeBook(const int grades[], int count)
        : grades_{}, count_(count) {
        for (int i = 0; i < count_; ++i) {
            grades_[i] = grades[i];
        }
    }

    GradeBook(const GradeBook& other)
        : grades_{}, count_(other.count_) {
        for (int i = 0; i < count_; ++i) {
            grades_[i] = other.grades_[i];
        }
    }

    void Replace(int index, int grade) {
        grades_[index] = grade;
    }

    int Sum() const {
        int sum = 0;

        for (int i = 0; i < count_; ++i) {
            sum += grades_[i];
        }

        return sum;
    }

    double Average() const {
        return static_cast<double>(Sum()) / count_;
    }

    void Print() const {
        std::cout << Sum() << ' '
                  << std::fixed << std::setprecision(2)
                  << Average() << '\n';
    }
};

int main() {
    int n;
    std::cin >> n;

    int grades[10]{};

    for (int i = 0; i < n; ++i) {
        std::cin >> grades[i];
    }

    int index, newGrade;
    std::cin >> index >> newGrade;

    GradeBook original(grades, n);
    GradeBook copy(original);

    copy.Replace(index, newGrade);

    original.Print();
    copy.Print();
}
