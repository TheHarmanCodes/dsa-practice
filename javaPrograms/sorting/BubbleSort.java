/**
 Bubble Sort Algorithm
 it is a In-place algo

 Time Complexity:
 Best Case: O(n) -> improved with flag variable
 Average Case: O(n^2)
 Worst Case: O(n^2)

 Space Complexity:
 O(1)

 */
package javaPrograms.sorting;

public class BubbleSort {
    /**
     * Sorts the given integer array in ascending order using an in-place bubble sort.
     *
     * This method mutates the input array and uses an early-exit optimization to stop
     * when the array becomes sorted before completing all passes.
     *
     * @param arr the array of integers to sort; its contents are rearranged in-place
     */
    public static void bubbleSort(int[] arr) {
        int size = arr.length, temp;
        boolean flag;

        for (int i = 0; i < size; i++) {
            flag = true;
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    flag = false;
                }
            }
            if (flag) {
                break;
            }
        }
    }
}
