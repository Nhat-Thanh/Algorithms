public class quick_sort {
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
        if (first < right)
            quickSort(arr, first, right);
        if (left < last)
            quickSort(arr, left, last);
    }

    public static void main(String[] args) {
        int[] arr = { 2, 7, 8, 4, -9, 0, -100, 20, 45, 3 };
        quickSort(arr, 0, 9);
        for (int index = 0; index < 10; ++index) 
            System.out.printf("%d ", arr[index]);
    }
}