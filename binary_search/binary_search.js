function binarySeach(arr, n, val) {
    var left = 0;
    var right = n - 1;
    var mid = (left + right) >> 1;
    
    while (arr[mid] != val && left < right) {
        if (val < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
        mid = (left + right) >> 1;
    }

    if (arr[mid] != val)
        return n;
    return mid;
}

var arr = [-100, -9, 0, 2, 3, 4, 7, 8, 20, 45];
console.log(binarySeach(arr, 10, -100))