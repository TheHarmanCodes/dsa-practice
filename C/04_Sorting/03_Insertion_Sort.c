// Problem Statement: C program to sort an array of integers using the Insertion Sort Algorithm

//  Time Complexity:
//  Best Case:    O(n)
//  Average Case: O(n^2)
//  Worst Case:   O(n^2)

// Space Complexity: O(1) (In-place sorting algorithm)

#include <stdio.h>
#define MAX 50

void insertionSort(int[], int);
int main()
{
    int A[MAX], i = 0, N = 0;
    printf("Enter Size of Array: ");
    scanf("%d", &N);

    printf("Enter Array Elements: ");
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    insertionSort(A, N);

    printf("Sorted Array:\n");
    for (i = 0; i < N; i++)
        printf("%d ", A[i]);
    return 0;
}

void insertionSort(int arr[], int n)
{
    int temp = 0, j = 0;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
