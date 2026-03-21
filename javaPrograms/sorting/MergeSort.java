/*
Merge Sort Algorithm

Time Complexity:
Best Case:    O(n log n)
Average Case: O(n log n)
Worst Case:   O(n log n)

space complexity: O(n)

*/

package javaPrograms.sorting;

public class MergeSort {
    /**
     * Sorts the elements in the array between indices lb and ub (inclusive) into ascending order using merge sort.
     *
     * @param arr the array whose specified range will be sorted (modified in place)
     * @param lb the lower bound index of the range to sort (inclusive)
     * @param ub the upper bound index of the range to sort (inclusive)
     */
    public static void mergeSort(int[] arr, int lb, int ub) {
        if (lb < ub) {
            int mid = (lb + ub) / 2;
            mergeSort(arr, lb, mid);
            mergeSort(arr, mid + 1, ub);
            merge(arr, lb, mid, ub);
        }
    }

    /**
     * Merges two consecutive sorted subarrays a[lb..mid] and a[mid+1..ub] into a single sorted range a[lb..ub].
     *
     * @param a   the array containing the two sorted subarrays; the merged result is written back into this array
     * @param lb  the lower (inclusive) index of the first sorted subarray
     * @param mid the end (inclusive) index of the first sorted subarray; the second subarray starts at mid + 1
     * @param ub  the upper (inclusive) index of the second sorted subarray
     */
    private static void merge(int[] a, int lb, int mid, int ub) {
        int i = lb, j = mid + 1, k = 0;
        int b[] = new int[ub - lb + 1];

        while (i <= mid && j <= ub) {
            if (a[i] <= a[j]) {
                b[k++] = a[i++];
            } else {
                b[k++] = a[j++];
            }
        }
        if (i > mid) {
            while (j <= ub) {
                b[k++] = a[j++];
            }
        } else {
            while (i <= mid) {
                b[k++] = a[i++];
            }
        }
        for (k = 0; k < b.length; k++) {
            a[lb + k] = b[k];
        }
    }
}
