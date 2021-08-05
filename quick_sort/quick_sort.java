public class quick_sort {
    public static void quickSort(int[] array, int first, int last) {
        int pivot = array[(first + last) >> 1];
        int left = first;
        int right = last;
        while (left <= right) {
            while (array[left] < pivot)
                left++;
            while (array[right] > pivot)
                right--;
            if (left <= right) {
                int temp = array[left];
                array[left] = array[right];
                array[right] = temp;

                left++;
                right--;
            }
        }
        if (first < right)
            quickSort(array, first, right);
        if (left < last)
            quickSort(array, left, last);
    }

    public static void main(String[] args) {
        int[] array = { 2, 7, 8, 4, -9, 0, -100, 20, 45, 3 };
        quickSort(array, 0, 9);
        for (int index = 0; index < 10; ++index) 
            System.out.printf("%d ", array[index]);
    }
}