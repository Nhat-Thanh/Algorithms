def binarySearch(arr, n, val):
    left = 0
    right = n - 1
    mid = (left + right) >> 1
    
    while (arr[mid] != val) and (left < right):
        if (val < arr[mid]):
            right = mid - 1
        else:
            left = mid + 1
        mid = (left + right) >> 1
    
    if (arr[mid] != val):
        return n
    return mid


arr = [-100, -9, 0, 2, 3, 4, 7, 8, 20, 45]
print(binarySearch(arr, 10, -100))