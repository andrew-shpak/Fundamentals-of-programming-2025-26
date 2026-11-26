#include <iostream>
#include <string>

class Ticket {
private:
    inline static int nextNumber_ = 1;

    const int number_;
    std::string event_;
    std::string holder_;

public:
    Ticket(const std::string& event,
           const std::string& holder)
        : number_(nextNumber_++),
          event_(event),
          holder_(holder) {}

    Ticket(const Ticket& other)
        : number_(nextNumber_++),
          event_(other.event_),
          holder_(other.holder_) {}

    void SetHolder(const std::string& holder) {
        holder_ = holder;
    }

    void Print() const {
        std::cout << number_ << ' '
                  << event_ << ' '
                  << holder_ << '\n';
    }
};

int main() {
    std::string event;
    std::string firstHolder, secondHolder, newHolder;

    std::cin >> event
             >> firstHolder >> secondHolder >> newHolder;

    Ticket first(event, firstHolder);
    Ticket second(event, secondHolder);
    Ticket copy(first);

    copy.SetHolder(newHolder);

    first.Print();
    second.Print();
    copy.Print();
}
