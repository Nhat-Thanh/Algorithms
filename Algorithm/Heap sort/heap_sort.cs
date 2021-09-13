public class heap_sort {
    public static void heaptify(int[] arr, int n, int index) {
        int largest = index;
        int left = (index << 1) + 1;
        int right = (index << 1) + 2;
        
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        if (largest != index) {
            int temp = arr[largest];
            arr[largest] = arr[index];
            arr[index] = temp;

            heaptify(arr, n, largest);
        }
    }

    public static void heapSort(int[] arr, int n) {
        for (int i = (n >> 1) - 1; i >= 0; i--)
            heaptify(arr, n, i);
        for (int i = n - 1; i >= 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heaptify(arr, i, 0);
        }
    }

    public static void Main(string[] argv) {
        int[] arr = { 2, 7, 8, 4, -9, 0, -100, 20, 45, 3 };
        heapSort(arr, 10);
        for (int i = 0; i < 10; ++i)
            System.Console.Write(string.Format("{0} ", arr[i]));
    }
}