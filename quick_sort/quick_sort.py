import sys

def quickSort(array, first, last):
    pivot = array[(first + last) >> 1]
    left = first
    right = last

    while (left <= right):
        while (array[left] < pivot):
            left += 1
        while (array[right] > pivot):
            right -= 1

        if (left <= right):
            temp = array[left]
            array[left] = array[right]
            array[right] = temp

            left += 1
            right -= 1
        
    if (first < right):
        quickSort(array, first, right)
    if (left < last):
        quickSort(array, left, last)


arr = [2, 7, 8, 4, -9, 0, -100, 20, 45, 3]
quickSort(arr, 0, 9)
for element in arr:
    sys.stdout.write(f"{element} ");
    