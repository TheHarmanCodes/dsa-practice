package javaPrograms.searching;

// Time Complexity:
// WorstCase: O(log n)
// Best Case: O(1) when element is present in the mid, so we only need one comparison with mid

public class BinarySearch {
    // iterative approach
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

    // Recursive approach
    public static int binarySearchRec(int arr[], int key, int low, int high) {
        if (low > high) {
            return -1;
        }

        int mid = (low + high) / 2;
        if (key == arr[mid]) {
            return mid;
        } else if (key > arr[mid]) {
            return binarySearchRec(arr, key, mid + 1, high);
        } else {
            return binarySearchRec(arr, key, low, mid - 1);
        }
    }
}