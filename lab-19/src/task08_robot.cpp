#include <iostream>
#include <string>

class Module {
private:
    std::string name_;

public:
    explicit Module(const std::string& name)
        : name_(name) {
        std::cout << "START " << name_ << '\n';
    }

    ~Module() {
        std::cout << "STOP " << name_ << '\n';
    }
};

class Robot {
private:
    Module controller_;
    Module motor_;

public:
    Robot(const std::string& controllerName,
          const std::string& motorName)
        : controller_(controllerName),
          motor_(motorName) {
        std::cout << "ROBOT READY\n";
    }

    ~Robot() {
        std::cout << "ROBOT OFF\n";
    }
};

int main() {
    std::string controllerName, motorName;
    std::cin >> controllerName >> motorName;

    {
        Robot robot(controllerName, motorName);
        std::cout << "WORK\n";
    }

    std::cout << "END\n";
}
