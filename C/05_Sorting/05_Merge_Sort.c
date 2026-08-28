// Problem Statement: C program to sort an array of integers using the Merge Sort Algorithm
// Merge Sort is a Divide and Conquer sorting algorithm
// It is also widely used in External Sorting for large datasets

// Time Complexity:
// Best Case:    O(n log n)
// Average Case: O(n log n)
// Worst Case:   O(n log n)

// Space Complexity: O(n)

#define MAX 50

void mergeSort(int arr[], int lb, int ub);
void merge(int arr[], int lb, int mid, int ub);

void mergeSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

void merge(int arr[], int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = lb;
    int res[MAX];

    while (i <= mid && j <= ub)
    {
        if (arr[i] < arr[j])
        {
            res[k] = arr[i];
            i++;
        }
        else
        {
            res[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            res[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            res[k] = arr[i];
            i++;
            k++;
        }
    }
    for (k = lb; k <= ub; k++)
    {
        arr[k] = res[k];
    }
}
