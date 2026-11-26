#include <iostream>

class Dimensions {
private:
    int length_;
    int width_;
    int height_;

public:
    Dimensions(int length, int width, int height)
        : length_(length),
          width_(width),
          height_(height) {}

    Dimensions(const Dimensions& other) = default;

    int Volume() const {
        return length_ * width_ * height_;
    }

    void SetHeight(int height) {
        height_ = height;
    }
};

class Parcel {
private:
    Dimensions dimensions_;
    int weight_;

public:
    Parcel(int length, int width, int height, int weight)
        : dimensions_(length, width, height),
          weight_(weight) {}

    Parcel(const Parcel& other)
        : dimensions_(other.dimensions_),
          weight_(other.weight_) {}

    void ChangeHeight(int height) {
        dimensions_.SetHeight(height);
    }

    int Volume() const {
        return dimensions_.Volume();
    }

    int Cost() const {
        int weightUnits = (weight_ + 999) / 1000;
        int volumeUnits = (Volume() + 999) / 1000;

        return 30 + 7 * weightUnits + 2 * volumeUnits;
    }

    void Print() const {
        std::cout << Volume() << ' ' << Cost() << '\n';
    }
};

int main() {
    int length, width, height, weight, newHeight;
    std::cin >> length >> width >> height
             >> weight >> newHeight;

    Parcel original(length, width, height, weight);
    Parcel copy(original);

    copy.ChangeHeight(newHeight);

    original.Print();
    copy.Print();
}
