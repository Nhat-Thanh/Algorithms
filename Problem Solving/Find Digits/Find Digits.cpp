#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;

    while (n > 0) {
        int a = 1;
        std::cin >> a;

        int count = 0;
        int num = a;
        while (num > 0) {
            int d = num % 10;
            count += (!(d == 0) && (a % d == 0));
            num = num / 10;
        }
        std::cout << count << '\n';
        --n;
    }
    return 0;
}