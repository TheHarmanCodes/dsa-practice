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
    public static void quickSort(int[] arr, int lb, int ub) {
        int loc;
        if (lb < ub) {
            loc = partition(arr, lb, ub);
            quickSort(arr, lb, loc - 1);
            quickSort(arr, loc + 1, ub);
        }
    }

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

    private static void swap(int[] arr, int x, int y) {
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }
}
