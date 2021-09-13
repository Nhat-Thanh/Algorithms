var tempArr = new Array(10);

function mergeSort(arr, first, last) {
    if (first == last)
        return;
    var mid = (first + last) >> 1;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid + 1, last);

    var left = first;
    var right = mid + 1;
    var limit = 0;
    
    while (left <= mid || right <= last) {
        if (left > mid)
            tempArr[limit++] = arr[right++]
        else if (right > last)
            tempArr[limit++] = arr[left++];
        else if (arr[left] < arr[right])
            tempArr[limit++] = arr[left++];
        else
            tempArr[limit++] = arr[right++];
    }

    for (var i = 0; i < limit; ++i)
        arr[first + i] = tempArr[i];
}

var arr = [2, 7, 8, 4, -9, 0, -100, 20, 45, 3]
mergeSort(arr, 0, 9)
console.log(arr)