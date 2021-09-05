#include <iostream>

void quickSort(int arr[],
               const int& first,
               const int& last) {
    int pivot = arr[(first + last) >> 1];
    int left = first;
    int right = last;

    while (left <= right) {
        while (arr[left] < pivot)
            left++;
        while (arr[right] > pivot)
            right--;

        if (left <= right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    if (first < right)
        quickSort(arr, first, right);
    if (left < last)
        quickSort(arr, left, last);
}

int main() {
    int arr[10] = {2, 7, 8, 4, -9, 0, -100, 20, 45, 3};
    quickSort(arr, 0, 9);
    for (int index = 0; index < 10; ++index)
        std::cout << arr[index] << " ";
    return 0;
}