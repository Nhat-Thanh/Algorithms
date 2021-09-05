function heapify(arr, n, index) {
    var largest = index;
    var left = (index << 1) + 1;
    var right = (index << 1) + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != index) {
        let temp = arr[largest];
        arr[largest] = arr[index];
        arr[index] = temp;

        heapify(arr, n, largest);
    }
}

function heapSort(arr, n) {
    for (let i = (n >> 1) - 1; i >= 0; --i)
        heapify(arr, n, i);
    
    for (let i = n - 1; i >= 0; --i) {
        let temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

var arr = [2, 7, 8, 4, -9, 0, -100, 20, 45, 3];
heapSort(arr, 10);
console.log(arr)