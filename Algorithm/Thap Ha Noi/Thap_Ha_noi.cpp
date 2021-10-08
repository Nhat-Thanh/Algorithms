#include <iostream>

void move(int n, char a, char b, char c) {
    if (n == 1)
        std::cout << a << "->" << c << '\n';
    else {
        move(n - 1, a, c, b);
        std::cout << a << "->" << c << '\n';
        move(n - 1, b, a, c);
    }
}

int main() {
    int n;
    std::cin >> n;
    move(n, 'A', 'B', 'C');
    return 0;
}
