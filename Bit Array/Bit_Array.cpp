#include <iostream>
#include <cmath>

int main() {
    uint_fast64_t N, S, P, Q;
    std::cin >> N >> S >> P >> Q;

    const uint_fast64_t p2_31 = static_cast<uint_fast64_t>(pow(2, 31));

    uint_fast64_t cur, prev, count;
    prev = S % p2_31;
    count = 1;
    N = N - 1;

    bool isContinue = true;
    while (N > 0 && isContinue) {
        cur = (prev * P + Q) % p2_31;
        if (cur xor prev) {
            prev = cur;
            ++count;
        } else {
            isContinue = false;
        }
        N = N - 1;
    }   
     
    std::cout << count;
    return 0;
}