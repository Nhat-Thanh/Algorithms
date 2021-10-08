// A -> Z : 65 -> 90
// a -> z : 97 -> 122

#include <iostream>
#include <map>
#include <string>

char charmap[256];

int converse(int val, int step, const int& begin, const int& end) {
    val += step;
    if (val > end) {
        val = begin + (val - end) - 1;
    }
    return val;
}

void ceasar_encryption(std::string& str, int step) {
    step %= 26;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] < 64 || (str[i] > 90 && str[i] < 97) || str[i] > 122)
            continue;
        str[i] = charmap[str[i]];
    }
}

int main() {
    std::string str;
    std::cout << "type string: ";
    getline(std::cin, str);

    std::cout << "type step: ";
    int step;
    std::cin >> step;

    for (int i = 0; i < 26; ++i) {
        charmap[65 + i] = converse(65 + i, step, 65, 90);
        charmap[97 + i] = converse(97 + i, step, 97, 122);
    }

    ceasar_encryption(str, step);

    std::cout << str;
    return 0;
}
