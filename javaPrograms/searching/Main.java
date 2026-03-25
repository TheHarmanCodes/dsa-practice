package javaPrograms.searching;

import java.util.Scanner;
import javaPrograms.sorting.MergeSort;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Array Size: ");
        int size = sc.nextInt();
        if (size <= 0) {
            System.out.println("Invalid size. Must be greater than 0");
            sc.close();
            return;
        }

        int arr[] = new int[size];

        System.out.println("Enter Array elements: ");
        for (int i = 0; i < size; i++)
            arr[i] = sc.nextInt();

        int choice, key, pos = -1;
        System.out.print("\nEnter Key to search: ");
        key = sc.nextInt();

        System.out.print("\nChoose Searching Algorithm\n1. Linear Search\n2. Binary Search\nEnter choice: ");
        choice = sc.nextInt();

        switch (choice) {
            case 1:
                pos = LinearSearch.linearSearch(arr, key);
                break;

            case 2:
                MergeSort.mergeSort(arr, 0, arr.length - 1);
                pos = BinarySearch.binarySearch(arr, key);
                break;

            default:
                System.out.println("\nInvalid Choice!");
                sc.close();
                return;
        }

        if (pos == -1) {
            System.out.println(key + " is not found");
        } else {
            System.out.println(key + " is found at position " + pos);
        }
        sc.close();
    }
}
