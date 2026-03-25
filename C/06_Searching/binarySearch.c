int binarySearch(int arr[], int size, int key)
{
    int lb = 0, ub = size - 1, mid;

    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (key == arr[mid]) // best case if it hit first time
            return mid + 1;
        else if (key < arr[mid])
            ub = mid - 1;
        else
            lb = mid + 1;
    }
    return -1;
}

// Time Complexity: O(log n)