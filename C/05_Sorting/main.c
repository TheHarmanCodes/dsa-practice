#include <stdio.h>
#include "01_bubble_Sort.c"
#include "02_Selection_Sort.c"
#include "03_Insertion_Sort.c"
#include "04_Quick_Sort.c"
#include "05_Merge_Sort.c"
#define MAX 50

static void printArray(int arr[], int n)
{
    int i = 0;

    printf("Sorted Array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int A[MAX], i = 0, n = 0, choice = 0;

    printf("Enter Size of Array: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid size. Must be between 1 and %d\n", MAX);
        return 1;
    }

    printf("Enter Array Elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("\nChoose Sorting Algorithm\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Quick Sort\n5. Merge Sort\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        bubbleSort(A, n);
        break;
    case 2:
        selectionSort(A, n);
        break;
    case 3:
        insertionSort(A, n);
        break;
    case 4:
        quickSort(A, 0, n - 1);
        break;
    case 5:
        mergeSort(A, 0, n - 1);
        break;
    default:
        printf("Invalid choice!\n");
        return 1;
    }

    printArray(A, n);
    return 0;
}
