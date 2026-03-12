// Problem Statement: C program to sort an array of integers using the Selection Sort Algorithm
// selection sort can have 1 or 0 exchange in each pass
//  Time Complexity:
//  Best Case:    O(n^2)
//  Average Case: O(n^2)
//  Worst Case:   O(n^2)

// Space Complexity: O(1) (In-place sorting algorithm)

#include <stdio.h>
#define MAX 50

void selectionSort(int[], int);
int main()
{
    int A[MAX], i = 0, N = 0;
    printf("Enter Size of Array: ");
    scanf("%d", &N);

    printf("Enter Array Elements: ");
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    selectionSort(A, N);

    printf("Sorted Array:\n");
    for (i = 0; i < N; i++)
        printf("%d ", A[i]);

    return 0;
}

void selectionSort(int arr[], int n)
{
    int temp = 0, min = 0; // min will be holding minimum element index
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}