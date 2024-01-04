#include <stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[5] = {43, 54, 77, 89, 97};
    int key = 77;
    if (binarySearch(arr, 5, key) != -1)
        printf("Key found at index: %d\n", binarySearch(arr, 5, key));
    else
        printf("Element not found.\n");
    return 0;
}
