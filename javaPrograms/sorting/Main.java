package javaPrograms.sorting;

import java.util.Scanner;

public class Main {
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
