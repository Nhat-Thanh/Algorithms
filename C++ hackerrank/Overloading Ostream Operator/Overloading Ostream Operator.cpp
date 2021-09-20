#include <iostream>

class Person {
  public:
    Person(const std::string& first_name, const std::string& last_name)
        : first_name_(first_name),
          last_name_(last_name) {}

    const std::string& get_first_name() const {
        return first_name_;
    }

    const std::string& get_last_name() const {
        return last_name_;
    }

  private:
    std::string first_name_;
    std::string last_name_;
};
// Enter your code here.

std::ostream& operator<<(std::ostream& out, const Person& p) {
    out << "first_name=";
    out << p.get_first_name();
    out << ",last_name=";
    out << p.get_last_name();
    return out;
}

int main() {
    std::string first_name, last_name, event;
    std::cin >> first_name >> last_name >> event;
    auto p = Person(first_name, last_name);
    std::cout << p << " " << event << '\n';
    return 0;
}