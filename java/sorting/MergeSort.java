import java.util.Random;

public class MergeSort {

    private static int[] merge(int[] left, int[] right) {
        int n = left.length + right.length;
        int[] merged = new int[n];

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < left.length && j < right.length) {
            if (left[i] < right[j]) {
                merged[k] = left[i];
                i++;
                k++;
            } else {
                merged[k] = right[j];
                j++;
                k++;
            }
        }

        while (i < left.length) {
            merged[k] = left[i];
            i++;
            k++;
        }

        while (j < right.length) {
            merged[k] = right[j];
            j++;
            k++;
        }

        return merged;
    }

    private static int[] mergeSort(int[] numbers) {
        if (numbers.length == 1) {
            return numbers;
        }
        int m = numbers.length / 2;
        int[] left = new int[m];
        int[] right = new int[numbers.length - m];
        System.arraycopy(numbers, 0, left, 0, m);
        System.arraycopy(numbers, m, right, 0, numbers.length - m);
        left = mergeSort(left);
        right = mergeSort(right);
        return merge(left, right);
    }

    private static void printArray(int[] array) {
        for (int i = 0; i < array.length; i++){
            System.out.print(array[i] + " ");
        }
    }

    public static void main(String[] args) {
        int numberOfElements = 10;
        Random rand = new Random();
        int[] numbers = new int[numberOfElements];

        System.out.println("Unsorted Array:");
        for (int i = 0; i < numberOfElements; i++){
            numbers[i] = rand.nextInt(150) + 1;
            System.out.print(numbers[i] + " ");
        }

        int[] sorted = mergeSort(numbers);

        System.out.println("\nSorted Array:");
        for (int i = 0; i < numberOfElements; i++){
            System.out.print(sorted[i] + " ");
        }
    }
}
