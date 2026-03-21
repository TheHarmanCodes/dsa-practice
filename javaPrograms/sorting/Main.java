package javaPrograms.sorting;

import java.util.Scanner;

public class Main {
    /**
     * Runs an interactive console program that reads an integer array from standard input,
     * prompts the user to choose a sorting algorithm, applies the chosen algorithm to sort
     * the array in-place, and prints the sorted array.
     *
     * <p>Available choices:
     * <ul>
     *   <li>1 — Bubble Sort</li>
     *   <li>2 — Selection Sort</li>
     *   <li>3 — Insertion Sort</li>
     *   <li>4 — Quick Sort</li>
     *   <li>5 — Merge Sort</li>
     * </ul>
     *
     * @param args command-line arguments (not used)
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Array Size: ");
        int size = sc.nextInt();

        int arr[] = new int[size];

        System.out.println("Enter Array elements: ");
        for (int i = 0; i < size; i++)
            arr[i] = sc.nextInt();

        System.out.println(
                "\nChoose Sorting Algorithm:\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Quick Sort\n5. Merge Sort\nEnter Choice: ");
        int choice = sc.nextInt();
        switch (choice) {
            case 1:
                BubbleSort.bubbleSort(arr);
                break;
            case 2:
                SelectionSort.selectionSort(arr);
                break;
            case 3:
                InsertionSort.insertionSort(arr);
                break;
            case 4:
                QuickSort.quickSort(arr, 0, size - 1);
                break;
            case 5:
                MergeSort.mergeSort(arr, 0, size - 1);
                break;

            default:
                System.out.println("\nInvalid Choice!");
                break;
        }

        System.out.println("\nArray after sorting: ");
        for (int num : arr) {
            System.out.print(num + " ");
        }
        sc.close();
    }
}
