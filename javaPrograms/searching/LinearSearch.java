package javaPrograms.searching;

public class LinearSearch {
    public static int linearSearch(int[] arr, int key) {
        for (int i = 0; i < arr.length; i++) {
            if (key == arr[i]) {
                return i + 1;// returning the position of found element
            }
        }
        return -1;
    }
}
// Time Complexity: O(n)