tempArr = [0] * 10

def mergeSort(arr, first, last):
    if first == last:
        return
    mid = (first + last) >> 1
    mergeSort(arr, first, mid)
    mergeSort(arr, mid + 1, last)

    left = first
    right = mid + 1
    limit = 0
    while (left <= mid) or (right <= last):
        if left > mid:
            tempArr[limit] = arr[right]
            limit += 1
            right += 1
        elif right > last:
            tempArr[limit] = arr[left]
            limit += 1
            left += 1
        elif arr[left] < arr[right]:
            tempArr[limit] = arr[left]
            limit += 1
            left += 1
        else:
            tempArr[limit] = arr[right]
            limit += 1
            right += 1

    i = 0
    while i < limit:
        arr[first + i] = tempArr[i]
        i += 1


arr = [2, 7, 8, 4, -9, 0, -100, 20, 45, 3]
mergeSort(arr, 0, 9)
print(arr)
