// Time Complexity:
// WorstCase: O(log n)
// Best Case: O(1) when element is present in the mid, so we only need one comparison with mid

// iterative approach
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

// recursive approach
int binarySearchRec(int arr[], int key, int low, int high)
{
    // base case
    if (low > high)
        return -1; // key not found

    int mid = (low + high) / 2;
    if (key == arr[mid])
        return mid;

    else if (key > arr[mid])
        // recursively search on right side
        binarySearchRec(arr, key, mid + 1, high);

    else
        // recursively search on left side
        binarySearchRec(arr, key, low, mid - 1);
}