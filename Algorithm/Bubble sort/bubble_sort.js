function bubbleSort(arr, n) {
    for (var i = 0; i < n; ++i)
        for (var j = i + 1; j < n; ++j)
            if (arr[j] < arr[i]) {
                var temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

var arr = [2, 7, 8, 4, -9, 0, -100, 20, 45, 3];
bubbleSort(arr, 10);
console.log(arr);