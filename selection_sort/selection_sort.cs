class selection_sort {
    public static void selectionSort(int[] arr, int n) {
        for (int i = 0; i < n; ++i) {
            int minIdx = i;
            for (int j = i + 1; j < n; ++j) 
                if (arr[j] < arr[minIdx]) 
                    minIdx = j;
                    
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        }
    }

    public static void Main(string[] argv) {
        int[] arr = { 2, 7, 8, 4, -9, 0, -100, 20, 45, 3 };
        selectionSort(arr, 10);
        for (int index = 0; index < 10; ++index)
            System.Console.Write(string.Format("{0} ",arr[index]));
    }
}