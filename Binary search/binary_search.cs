class binary_search {
    public static int binarySearch(int[] arr, int n, int val) {
        int left = 0;
        int right = n - 1;
        int mid = (left + right) >> 1;
        
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

    public static void Main(string[] args) {
        int[] arr = { -100, -9, 0, 2, 3, 4, 7, 8, 20, 45 };
        System.Console.Write(binarySearch(arr, 10, -100));
    }
}