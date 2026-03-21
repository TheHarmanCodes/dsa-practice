/* 
Quick Sort Algorithm
- it is In-place sorting algo as same array used
- Unstable algo as original order may change if elements are same

TimeComplexity:
Best Case : O(n log n)
Average Case : O(n log n)
Worst Case: O(n^2)

Space Complexity: O(log n) average, O(n) worst case -- due to Recursion Stack

*/

package javaPrograms.sorting;

public class QuickSort {
    /**
     * Sorts the elements of the given array between the indices {@code lb} and {@code ub} (inclusive) in ascending order using an in-place Quick Sort.
     *
     * The method modifies {@code arr} directly. If {@code lb >= ub} the range is already sorted and the method returns immediately.
     *
     * @param arr the array to sort; must not be {@code null}
     * @param lb  the lower bound index of the range to sort (inclusive)
     * @param ub  the upper bound index of the range to sort (inclusive)
     */
    public static void quickSort(int[] arr, int lb, int ub) {
        int loc;
        if (lb < ub) {
            loc = partition(arr, lb, ub);
            quickSort(arr, lb, loc - 1);
            quickSort(arr, loc + 1, ub);
        }
    }

    /**
     * Partitions the subarray arr[lb..ub] around a pivot chosen as arr[lb], placing the pivot in its final sorted position.
     *
     * @param arr the array containing the subarray to partition
     * @param lb  lower index of the subarray (inclusive)
     * @param ub  upper index of the subarray (inclusive)
     * @return    the index where the pivot element is placed after partitioning
     */
    private static int partition(int[] arr, int lb, int ub) {
        int pivot = arr[lb], start = lb, end = ub;

        while (start < end) {
            while (start <= ub && arr[start] <= pivot) {
                start++;
            }
            while (arr[end] > pivot) {
                end--;
            }
            if (start < end) {
                swap(arr, start, end);
            }
        }
        swap(arr, lb, end);
        return end;
    }

    /**
     * Exchanges the elements at the two specified indices in the given array.
     *
     * @param arr the array containing elements to swap
     * @param x   the index of the first element to swap
     * @param y   the index of the second element to swap
     */
    private static void swap(int[] arr, int x, int y) {
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }
}
