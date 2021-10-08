#include <iostream>

int main() {
    int n, i, j;
    std::cin >> n;
    int* arr = new int[n];

    for (i = 0; i < n; ++i)
        std::cin >> arr[i];

    for (i = 1; i < n; ++i) {
        int a = arr[i];
        j = i - 1;
        while (j > -1) {
            if (arr[j] > a)
                arr[j + 1] = arr[j];
            else
                break;
            --j;
        }
        arr[j + 1] = a;
    }

    for (i = 0; i < n; ++i)
        std::cout << arr[i] << " ";

    return 0;
}