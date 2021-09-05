#include <iostream>

void selectionSort(int arr[], const int& n) {
    for (int i = 0; i < n; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        std::swap(arr[minIdx], arr[i]);
    }
}

int main() {
    int arr[10] = {2, 7, 8, 4, -9, 0, -100, 20, 45, 3};
    selectionSort(arr, 10);
    for (int index = 0; index < 10; ++index)
        std::cout << arr[index] << " ";
    return 0;
}
