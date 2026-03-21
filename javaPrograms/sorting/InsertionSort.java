/*
Insertion Sort Algorithm

Time Complexity:
Best Case:    O(n)
Average Case: O(n^2)
Worst Case:   O(n^2)

Space Complexity: O(1) (In-place sorting algorithm)
 */
package javaPrograms.sorting;

public class InsertionSort {
    public static void insertionSort(int[] arr) {
        int temp, j;
        for (int i = 1; i < arr.length; i++) {
            temp = arr[i];
            j = i - 1;
            while (j >= 0 && temp < arr[j]) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }
}
