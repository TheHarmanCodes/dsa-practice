/*
Selection Sort Algorithm
Time Complexity:
Best Case:    O(n^2)
Average Case: O(n^2)
Worst Case:   O(n^2)

Space Complexity: O(1) (In-place sorting algorithm)
*/
package javaPrograms.sorting;

public class SelectionSort {
    /**
     * Sorts the given integer array in ascending order using selection sort.
     *
     * The array is modified in place; no value is returned.
     *
     * @param arr the array whose elements will be reordered into ascending order
     */
    public static void selectionSort(int[] arr) {
        int size = arr.length, min, temp;
        for (int i = 0; i < size - 1; i++) {
            min = i; // min array index
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            if (min != i) {
                temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
        }
    }
}