import sys
arrayTemp = []

def mergeSort(array, first, last):
    if first == last:
        return
    mid = (first + last) >> 1
    mergeSort(array, first, mid)
    mergeSort(array, mid + 1, last)

    left = first
    right = mid + 1
    while (left <= mid) or (right <= last):
        if left > mid:
            arrayTemp.append(array[right])
            right += 1
        elif right > last:
            arrayTemp.append(array[left])
            left += 1
        elif array[left] < array[right]:
            arrayTemp.append(array[left])
            left += 1
        else:
            arrayTemp.append(array[right])
            right += 1
    
    i = 0
    while i < len(arrayTemp):
        array[first + i] = arrayTemp[i]
        i += 1
    arrayTemp.clear()
    

arr = [2, 7, 8, 4, -9, 0, -100, 20, 45, 3]
mergeSort(arr, 0, 9)
for element in arr:
    sys.stdout.write(f"{element} ");