function selectionSort(arr, n) {
    for (var i = 0; i < n; ++i) {
        var minIdx = i;
        for (var j = i + 1; j < n; ++j)
            if (arr[j] < arr[minIdx]) 
                minIdx = j;
        
        var temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
        
}

var arr = [2, 7, 8, 4, -9, 0, -100, 20, 45, 3];
selectionSort(arr, 10);
console.log(arr);