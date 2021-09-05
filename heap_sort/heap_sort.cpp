#include <iostream>

void heapify(int arr[],
             const int& n,
             const int& index) {
    int largest = index;
    int left = (index << 1) + 1;
    int right = (index << 1) + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest xor index) {
        std::swap(arr[largest], arr[index]);
        heapify(arr, n, largest);
    }
}

void heapSort(int* arr, const int& n) {
    for (int i = (n >> 1) - 1; i >= 0; --i)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[10] = {2, 7, 8, 4, -9, 0, -100, 20, 45, 3};
    heapSort(arr, 10);
    for (int index = 0; index < 10; ++index)
        std::cout << arr[index] << " ";
    return 0;
}