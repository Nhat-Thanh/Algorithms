#include <iostream>
#include <vector>
#include <stdint.h>
#include <assert.h>

void factorial(int n) {
    assert(n >= 0);
    std::vector<int16_t> digits;
    digits.emplace_back(1);
    int num_digits = 1;
    int temp, cache_num = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < num_digits; ++j) {
            temp = digits[j] * i + cache_num;
            cache_num = temp / 10;
            digits[j] = temp % 10;
        }
        while (cache_num > 0) {
            digits.emplace_back(cache_num % 10);
            cache_num /= 10;
            num_digits += 1;
        }
    }
    for (int i = num_digits - 1; i >= 0; --i)
        std::cout << digits[i];
}

int main() {
    int n;
    std::cin >> n;
    factorial(n);
}



// void factorial(int n) {
//     std::vector<int> digits;
//     int i, j;
//     int SoNho, temp, num_digits;
//     SoNho = 0;
//     num_digits = 1;
//     digits.emplace_back(1);
//     for (i = 2; i <= n; ++i) {
//         for (j = 0; j < num_digits; ++j) {
//             temp = (digits[j] * i + SoNho);
//             SoNho = temp / 10;
//             digits[j] = temp % 10;
//         }
//         while (SoNho > 0) {
//             digits.emplace_back(SoNho % 10);
//             ++num_digits;
//             SoNho /= 10;
//         }
//     }
//     for (i = num_digits - 1; i >= 0; --i)
//         std::cout << digits[i];
// }