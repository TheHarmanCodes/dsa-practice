// Problem Statement: C program to sort an array of integers using the Bubble Sort Algorithm

//  Time Complexity:
//  Best Case:   O(n)      -> When the array is already sorted (optimized using flag)
//  Average Case: O(n^2)
//  Worst Case:   O(n^2)

// Space Complexity: O(1) (In-place sorting algorithm)

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
