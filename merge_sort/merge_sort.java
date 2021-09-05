public class merge_sort {
    static int[] tempArr = new int[10];

    public static void mergeSort(int[] arr, int first, int last) {
        if (first == last)
            return;
        int mid = (first + last) >> 1;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);

        int left = first;
        int right = mid + 1;
        int limit = 0;
        while (left <= mid || right <= last) {
            if (left > mid)
                tempArr[limit++] = arr[right++];
            else if (right > last)
                tempArr[limit++] = arr[left++];
            else if (arr[left] < arr[right])
                tempArr[limit++] = arr[left++];
            else
                tempArr[limit++] = arr[right++];
        }

        for (int i = 0; i < limit; ++i)
            arr[first + i] = tempArr[i];
    }

    public static void main(String[] args) {
        int[] arr = { 2, 7, 8, 4, -9, 0, -100, 20, 45, 3 };
        mergeSort(arr, 0, 9);
        for (int index = 0; index < 10; ++index)
            System.out.printf("%d ", arr[index]);
    }
}