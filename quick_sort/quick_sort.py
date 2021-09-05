import sys

def quickSort(arr, first, last):
    pivot = arr[(first + last) >> 1]
    left = first
    right = last

    while (left <= right):
        while (arr[left] < pivot):
            left += 1
        while (arr[right] > pivot):
            right -= 1

        if (left <= right):
            temp = arr[left]
            arr[left] = arr[right]
            arr[right] = temp

            left += 1
            right -= 1
        
    if (first < right):
        quickSort(arr, first, right)
    if (left < last):
        quickSort(arr, left, last)


arr = [2, 7, 8, 4, -9, 0, -100, 20, 45, 3]
quickSort(arr, 0, 9)
print(arr)
    