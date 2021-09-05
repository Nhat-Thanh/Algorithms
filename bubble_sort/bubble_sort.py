def bubbleSort(arr, n):
    i = 0
    while (i < n):
        j = i + 1
        while (j < n):
            if (arr[i] > arr[j]):
                temp = arr[i]
                arr[i] = arr[j]
                arr[j] = temp
            j += 1
        i += 1


arr = [2, 7, 8, 4, -9, 0, -100, 20, 45, 3]
bubbleSort(arr, 10)
print(arr)