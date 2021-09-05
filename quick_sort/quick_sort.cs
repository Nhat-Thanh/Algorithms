class quick_sort {
    public static void quickSort(int[] arr, int first, int last) {
        int pivot = arr[(first + last) >> 1];
        int left = first;
        int right = last;

        while (left <= right) {
            while (arr[left] < pivot)
                left++;
            while (arr[right] > pivot)
                right--;
            
            if (left <= right) {
                int temp = arr[left];
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
    public static void Main(string[] argv) {
        int[] arr = { 2, 7, 8, 4, -9, 0, -100, 20, 45, 3 };
        quickSort(arr, 0, 9);
        for (int i = 0; i < 10; ++i)
            System.Console.Write(string.Format("{0} ", arr[i]));
    }
}