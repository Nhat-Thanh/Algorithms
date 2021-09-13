class bubble_sort {
    public static void bubbleSort(int[] arr, int n) {
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (arr[j] < arr[i]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
    }

    public static void main(String[] args) {
        int[] arr = { 2, 7, 8, 4, -9, 0, -100, 20, 45, 3 };
        bubbleSort(arr, 10);
        for (int i = 0; i < 10; ++i)
            System.out.printf("%d ", arr[i]);
    }
}