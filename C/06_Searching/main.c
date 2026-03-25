#include <stdio.h>
#include "linearSearch.c"
#include "binarySearch.c"
#include "../05_Sorting/05_Merge_Sort.c"
#define MAX 50

int main()
{
    int A[MAX], i = 0, n = 0, key, pos = -1, choice;
    printf("Enter Size of Array: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid size. Must be between 1 and %d", MAX);
        return 1;
    }

    printf("Enter Array Elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("\nEnter Key to search: ");
    scanf("%d", &key);

    printf("\nChoose Searching Algorithm\n1. Linear Search\n2: Binary Search\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        pos = linearSearch(A, n, key);
        break;
    case 2:
        mergeSort(A, 0, n - 1);
        pos = binarySearch(A, n, key);
        break;
    }
    if (pos == -1)
        printf("%d is not found", key);
    else
        printf("%d is found at position %d", key, pos);

    return 0;
}