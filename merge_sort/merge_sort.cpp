#include <iostream>

int arrayTemp[10];

void mergeSort(int array[], int first, int last) {
    if (first == last)
        return;
    int mid = (first + last) >> 1;
    mergeSort(array, first, mid);
    mergeSort(array, mid + 1, last);
    
    int left = first;
    int right = mid + 1;
    int limit = 0;

    while (left <= mid || right <= last) {
        if (left > mid)
            arrayTemp[limit++] = array[right++];
        else if (right > last)
            arrayTemp[limit++] = array[left++];
        else if (array[left] < array[right])
            arrayTemp[limit++] = array[left++];
        else
            arrayTemp[limit++] = array[right++];
    }

    for (int i = 0; i < limit; ++i)
        array[first + i] = arrayTemp[i];
}

int main() {
    int arr[10] = {2, 7, 8, 4, -9, 0, -100, 20, 45, 3};
    mergeSort(arr, 0, 9);
    for (int index = 0; index < 10; ++index)
        std::cout << arr[index] << " ";
    return 0;
}