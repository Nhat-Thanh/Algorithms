#include <iostream>
#include <stdexcept>

int largest_proper_divisor(int n) {
    if (n == 0) {
        throw std::invalid_argument("largest proper divisor is not defined for n=0");
    }
    if (n == 1) {
        throw std::invalid_argument("largest proper divisor is not defined for n=1");
    }
    for (int i = n / 2; i >= 1; --i) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1;     // will never happen
}

void process_input(int n) {
    try {
        int d = largest_proper_divisor(n);
        std::cout << "result=" << d << '\n';
        std::cout << "returning control flow to caller\n";
    } catch (std::invalid_argument& ex) {
        std::cout << ex.what() << "\n";
        std::cout << "returning control flow to caller\n";
    }
}

int main() {
    int n;
    std::cin >> n;
    process_input(n);
    return 0;
}