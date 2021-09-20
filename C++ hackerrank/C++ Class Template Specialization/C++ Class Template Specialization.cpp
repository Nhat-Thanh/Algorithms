#include <iostream>
enum class Fruit { apple,
                   orange,
                   pear };

enum class Color { red,
                   green,
                   orange };

template <typename T>
struct Traits;

std::string fruit[3] = {"apple", "orange", "pear"};
std::string color[3] = {"red", "green", "orange"};

template <>
struct Traits<Fruit> {
    static std::string name(int& index) {
        return (index > -1 && index < 3) ? fruit[index] : "unknown";
    }
};

template <>
struct Traits<Color> {
    static std::string name(int& index) {
        return (index > -1 && index < 3) ? color[index] : "unknown";
    }
};

int static start_up() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}

int static num = start_up();
#define endl '\n'

int main() {
    int t = 0;
    std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int index1;
        std::cin >> index1;
        int index2;
        std::cin >> index2;
        std::cout << Traits<Color>::name(index1) << " ";
        std::cout << Traits<Fruit>::name(index2) << "\n";
    }
}
