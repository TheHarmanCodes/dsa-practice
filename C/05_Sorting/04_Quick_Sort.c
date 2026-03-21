// Problem Statement: C program to sort an array of integers using the Quick Sort Algorithm
// Exchange sort algorithm

// Time Complexity:
// Best Case:    O(n log n)
// Average Case: O(n log n)
// Worst Case:   O(n^2)

// Space Complexity:
// Best Case:    O(log n)
// Average Case: O(log n)
// Worst Case:   O(n)

#include <stdio.h>
#define MAX 50

void quickSort(int[], int, int);
int partition(int[], int, int);
void swap(int[], int, int);

int main()
{
    int A[MAX], i = 0, N = 0;
    printf("Enter Size of Array: ");
    scanf("%d", &N);

    printf("Enter Array Elements: ");
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    quickSort(A, 0, N - 1); //(array, lowerbound, upperbound)

    printf("Sorted Array:\n");
    for (i = 0; i < N; i++)
        printf("%d ", A[i]);

    return 0;
}

void quickSort(int arr[], int lb, int ub)
{
    int loc;
    if (lb < ub)
    {
        loc = partition(arr, lb, ub);
        quickSort(arr, lb, loc - 1);
        quickSort(arr, loc + 1, ub);
    }
}

int partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb], start = lb, end = ub;

    while (start < end)
    {
        while (start <= ub && arr[start] <= pivot) // stop when greater element found left to right
            start++;

        while (arr[end] > pivot) // stop when smaller element is found from right to left
            end--;

        if (start < end)
            swap(arr, start, end);
    }
    swap(arr, lb, end); // now we got a correct position for pivot element
    return end;
}

void swap(int arr[], int x, int y)
{
    int temp = 0;
    temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}