// Problem Statement: C program to sort an array of integers using the Insertion Sort Algorithm

//  Time Complexity:
//  Best Case:    O(n)
//  Average Case: O(n^2)
//  Worst Case:   O(n^2)

// Space Complexity: O(1) (In-place sorting algorithm)

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
