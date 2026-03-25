package javaPrograms.searching;

public class BinarySearch {
    public static int binarySearch(int[] arr, int key) {
        int lb = 0, ub = arr.length - 1, mid;

        while (lb <= ub) {
            mid = (lb + ub) / 2;

            if (arr[mid] == key) {
                return mid + 1; // returning the position value
            } else if (arr[mid] > key) {
                ub = mid - 1;
            } else {
                lb = mid + 1;
            }
        }
        return -1;
    }
}
// Time Complexity: O(log n)