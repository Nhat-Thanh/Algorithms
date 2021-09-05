#include <iostream>

int tempArr[10];

void mergeSort(int arr[],
               const int& first,
               const int& last) {
    if (first == last)
        return;
    int mid = (first + last) >> 1;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid + 1, last);

    int left = first;
    int right = mid + 1;
    int limit = 0;

    while (left <= mid || right <= last) {
        if (left > mid)
            tempArr[limit++] = arr[right++];
        else if (right > last)
            tempArr[limit++] = arr[left++];
        else if (arr[left] < arr[right])
            tempArr[limit++] = arr[left++];
        else
            tempArr[limit++] = arr[right++];
    }

    for (int i = 0; i < limit; ++i)
        arr[first + i] = tempArr[i];
}

int main() {
    int arr[10] = {2, 7, 8, 4, -9, 0, -100, 20, 45, 3};
    mergeSort(arr, 0, 9);
    for (int index = 0; index < 10; ++index)
        std::cout << arr[index] << " ";
    return 0;
}