#include <iostream>

int main() {
    int n, lmax;
    std::cin >> n;
    int num_arr[n], lenght_arr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> num_arr[i];
        lenght_arr[i] = 1;
    }
    
    for (int i = 1; i < n; ++i) {
        lmax = 0;
        for (int j = 0; j < i; ++j) {
            if (num_arr[i] > num_arr[j] && lmax < lenght_arr[j])
                lmax = lenght_arr[j];
        }
        lenght_arr[i] = lmax + 1;
    }
    
    for (int i = 0; i < n; ++i)
        std::cout << lenght_arr[i] << " ";

    return 0;
}
