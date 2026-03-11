// Problem Statement: C program to sort an array of integers using the Bubble Sort Algorithm

//  Time Complexity:
//  Best Case:   O(n)      -> When the array is already sorted (optimized using flag)
//  Average Case: O(n^2)
//  Worst Case:   O(n^2)

// Space Complexity: O(1) (In-place sorting algorithm)

#include <stdio.h>
#define MAX 50

void bubbleSort(int[], int);
int main()
{
    int A[MAX], i = 0, N = 0;
    printf("Enter Size of Array: ");
    scanf("%d", &N);

    printf("Enter Array Elements: ");
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    bubbleSort(A, N);

    printf("Sorted Array:\n");
    for (i = 0; i < N; i++)
        printf("%d ", A[i]);

    return 0;
}

void bubbleSort(int arr[], int n)
{
    int i = 0, j = 0, temp = 0, flag = 0;
    for (i = 0; i < n; i++)
    {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}