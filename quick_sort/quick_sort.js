function quickSort(arr, first, last) {
    var pivot = arr[(first + last) >> 1];
    var left = first;
    var right = last;

    while (left <= right) {
        while (arr[left] < pivot)
            left++;
        while (arr[right] > pivot)
            right--;
        if (left <= right) {
            var temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }
    }
    if (left < last)
        quickSort(arr, left, last);
    if (first < right)
        quickSort(arr, first, right);
}

var arr = [2, 7, 8, 4, -9, 0, -100, 20, 45, 3];
quickSort(arr, 0, 9);
console.log(arr);