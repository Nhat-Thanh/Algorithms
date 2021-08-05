public class merge_sort {
    static int[] arrayTemp = new int[10];

    public static void mergeSort(int[] array, int first, int last) {
        if (first == last)
            return;
        int mid = (first + last) >> 1;
        mergeSort(array, first, mid);
        mergeSort(array, mid + 1, last);

        int left = first;
        int right = mid + 1;
        int limit = 0;
        while (left <= mid || right <= last) {
            if (left > mid)
                arrayTemp[limit++] = array[right++];
            else if (right > last)
                arrayTemp[limit++] = array[left++];
            else if (array[left] < array[right])
                arrayTemp[limit++] = array[left++];
            else
                arrayTemp[limit++] = array[right++];
        }

        for (int i = 0; i < limit; ++i)
            array[first + i] = arrayTemp[i];
    }

    public static void main(String[] args) {
        int[] array = { 2, 7, 8, 4, -9, 0, -100, 20, 45, 3 };
        mergeSort(array, 0, 9);
        for (int index = 0; index < 10; ++index)
            System.out.printf("%d ", array[index]);
    }
}