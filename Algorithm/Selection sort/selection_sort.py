def selectionSort(arr, n):
    i = 0
    while (i < n):
        minIdx = i
        j = i + 1
        while (j < n):
            if (arr[j] < arr[minIdx]):
                minIdx = j
            j += 1

        temp = arr[i]
        arr[i] = arr[minIdx]
        arr[minIdx] = temp
        i += 1


arr = [2, 7, 8, 4, -9, 0, -100, 20, 45, 3]
selectionSort(arr, 10)
print(arr)
