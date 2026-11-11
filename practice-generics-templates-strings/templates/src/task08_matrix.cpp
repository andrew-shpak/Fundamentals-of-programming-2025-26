#include <iostream>

template<typename T, int Rows, int Cols>
struct Matrix {
    static_assert(Rows > 0 && Cols > 0);
    T data[Rows][Cols]{};
    Matrix<T, Cols, Rows> Transpose() const {
        Matrix<T, Cols, Rows> result;
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) result.data[j][i] = data[i][j];
        }
        return result;
    }
};

int main() {
    Matrix<int, 2, 3> matrix;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!(std::cin >> matrix.data[i][j])) {
                std::cout << "Некоректні дані\n";
                return 0;
            }
        }
    }
    auto result = matrix.Transpose();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (j != 0) std::cout << ' ';
            std::cout << result.data[i][j];
        }
        std::cout << '\n';
    }
}
