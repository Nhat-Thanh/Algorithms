#include <iostream>

int binarySearch(int arr[],
                 const int& n,
                 const int& val) {
    int left = 0;
    int right = n - 1;
    int mid = (left + right) >> 1;

    while (arr[mid] != val && left < right) {
        if (arr[mid] > val)
            right = mid - 1;
        else
            left = mid + 1;
        mid = (left + right) >> 1;
    }
    
    if (arr[mid] != val)
        return n;
    return mid;
}

int main() {
    int arr[10] = {-100, -9, 0, 2, 3, 4, 7, 8, 20, 45};
    std::cout << binarySearch(arr, 10, -100);
    return 0;
}