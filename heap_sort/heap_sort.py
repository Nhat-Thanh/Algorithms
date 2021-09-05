import sys

def heapify(arr, n, index):
    largest = index
    left = (index << 1) + 1
    right = (index << 1) + 2

    if (left < n) and (arr[left] > arr[largest]):
        largest = left
    if (right < n) and (arr[right] > arr[largest]):
        largest = right

    if (largest != index):
        temp = arr[largest]
        arr[largest] = arr[index]
        arr[index] = temp

        heapify(arr, n, largest)

def heapSort(arr, n):
    i = (n >> 1) - 1
    while (i >= 0):
        heapify(arr, n, i)
        i -= 1
    
    i = n - 1
    while (i >= 0):
        temp = arr[0]
        arr[0] = arr[i]
        arr[i] = temp
        
        heapify(arr, i, 0)
        i -= 1


arr = [2, 7, 8, 4, -9, 0, -100, 20, 45, 3]
heapSort(arr, 10)
print(arr)