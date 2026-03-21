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
    public static void mergeSort(int[] arr, int lb, int ub) {
        if (lb < ub) {
            int mid = (lb + ub) / 2;
            mergeSort(arr, lb, mid);
            mergeSort(arr, mid + 1, ub);
            merge(arr, lb, mid, ub);
        }
    }

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
